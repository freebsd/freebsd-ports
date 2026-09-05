--- src/watchdog/__init__.py.orig
+++ src/watchdog/__init__.py
@@ -808,6 +808,58 @@ def get_file_safe_mountpoint(mount):
     return mountpoint + "." + opts["port"]
 
 
+def _get_freebsd_established_loopback_ports():
+    """
+    Return the set of local ports (as strings) with an ESTABLISHED tcp4
+    loopback (127.0.0.1) connection, per sockstat(1), or None if sockstat
+    could not be run. The kernel NFS client's connection to a live efs-proxy
+    shows up here; an orphaned efs-proxy (e.g. left over from a failed mount
+    attempt) only has its LISTEN socket, which sockstat reports with a
+    foreign address of "*:*".
+    """
+    try:
+        process = subprocess.run(
+            ["sockstat", "-4"],
+            stdout=subprocess.PIPE,
+            stderr=subprocess.DEVNULL,
+            universal_newlines=True,
+            timeout=5,
+        )
+    except Exception as e:
+        logging.warning("Unable to run sockstat: %s", e)
+        return None
+
+    established_ports = set()
+    for line in process.stdout.splitlines():
+        parts = line.split()
+        if len(parts) < 3:
+            continue
+        proto, local, foreign = parts[-3], parts[-2], parts[-1]
+        if not proto.startswith("tcp"):
+            continue
+        if foreign in ("*:*", "*.*"):
+            continue
+        if not local.startswith("127.0.0.1:"):
+            continue
+        established_ports.add(local.rsplit(":", 1)[1])
+    return established_ports
+
+
+def _freebsd_proxy_port_established(port):
+    """
+    Return True if `port` has an ESTABLISHED tcp4 loopback connection (efs-proxy
+    alive and serving the kernel NFS client), False if it does not, or None if
+    sockstat could not be run. Used by the FreeBSD stunnel health check in place
+    of a `df` probe: a live proxy keeps a persistent ESTABLISHED loopback socket
+    even when the mount is idle, whereas `df` measures the whole end-to-end path
+    (including the EFS backend) and times out on backend slowness alone.
+    """
+    established_ports = _get_freebsd_established_loopback_ports()
+    if established_ports is None:
+        return None
+    return port in established_ports
+
+
 def get_current_local_nfs_mounts(mount_file="/proc/mounts"):
     """
     Return a dict of the current NFS mounts for servers running on localhost, keyed by the mountpoint and port as it
@@ -815,7 +867,92 @@ def get_current_local_nfs_mounts(mount_file="/proc/mounts"):
     """
     mounts = []
 
-    if not check_if_running_on_macos():
+    if sys.platform.startswith("freebsd"):
+        # FreeBSD: no /proc/mounts, and neither mount(8) nor nfsstat(8) exposes
+        # the NFS client's TCP port. Use the watchdog's own state files as the
+        # source of truth: each mount created by mount.efs has a state file
+        #   fs-<id>.<mountpoint-with-slashes-as-dots>.<port>
+        # in STATE_FILE_DIR. Cross-check with `mount -t nfs` so we skip state
+        # files whose mountpoint has already been unmounted. State files (not
+        # live proxy sockets) are the source of truth for which mounts exist, so
+        # the watchdog still notices a dead efs-proxy and restarts it; sockstat
+        # is used only below to pick the live port when a mountpoint has more
+        # than one state file (see the dedup note there).
+        live_mps = set()
+        try:
+            process = subprocess.run(
+                ["mount", "-t", "nfs"],
+                check=True,
+                stdout=subprocess.PIPE,
+                universal_newlines=True,
+            )
+            for line in process.stdout.splitlines():
+                parts = line.split()
+                if len(parts) >= 3 and parts[1] == "on":
+                    live_mps.add(parts[2])
+        except Exception as e:
+            logging.warning("Unable to list NFS mounts: %s", e)
+
+        if live_mps:
+            try:
+                state_files = os.listdir(STATE_FILE_DIR)
+            except OSError:
+                state_files = []
+            # A mountpoint can end up with more than one state file/port pair,
+            # e.g. when mount.efs is retried on cold start after efs-proxy lost
+            # the race against mount_nfs: the failed attempt's efs-proxy + state
+            # file are never cleaned up, leaving a stale port alongside the one
+            # the mount actually uses. The kernel NFS client's loopback
+            # connection to the live proxy's port shows up as an ESTABLISHED
+            # tcp4 socket on 127.0.0.1:<port> in sockstat(1), whereas an
+            # orphaned proxy only has its LISTEN socket. Use that to identify
+            # the truly live port per mountpoint; any other duplicate for the
+            # same mountpoint is left out of the returned mounts so the existing
+            # stale-mount cleanup path in check_efs_mounts
+            # (mark_as_unmounted/clean_up_mount_state) can reap its orphaned
+            # efs-proxy and state file.
+            established_ports = _get_freebsd_established_loopback_ports()
+
+            candidates = {}
+            for sf in state_files:
+                if not sf.startswith("fs-"):
+                    continue
+                if sf.endswith("+") or "stunnel-config" in sf:
+                    continue
+                # fs-<id>.<mountpoint-with-slashes-as-dots>.<port>
+                stem_port = sf.rsplit(".", 1)
+                if len(stem_port) != 2:
+                    continue
+                stem, port = stem_port
+                try:
+                    int(port)
+                except ValueError:
+                    continue
+                inner = stem[len("fs-"):]
+                if "." not in inner:
+                    continue
+                _, _, mp_enc = inner.partition(".")
+                mp = "/" + mp_enc.replace(".", "/")
+                if mp not in live_mps:
+                    continue
+                is_established = established_ports is None or port in established_ports
+                current = candidates.get(mp)
+                # Prefer a port with a confirmed established loopback connection
+                # over one without; if sockstat is unavailable (established_ports
+                # is None) or ambiguous (e.g. more than one port for the
+                # mountpoint looks established, such as during the brief overlap
+                # of a watchdog-triggered restart), keep the first one found
+                # rather than silently dropping a possibly-live mount.
+                if current is None or (is_established and not current[1]):
+                    candidates[mp] = (port, is_established)
+
+            for mp, (port, _is_established) in candidates.items():
+                mounts.append(
+                    Mount._make(
+                        ["127.0.0.1:/", mp, "nfs", "port=" + port, 0, 0]
+                    )
+                )
+    elif not check_if_running_on_macos():
         with open(mount_file) as f:
             for mount in f:
                 try:
@@ -1548,6 +1685,65 @@ def check_stunnel_health(
         rewrite_state_file(state, state_file_dir, state_file)
 
     stunnel_pid = state["pid"]
+
+    if sys.platform.startswith("freebsd"):
+        # FreeBSD does not probe with `df`. `df` triggers an NFS GETATTR that
+        # traverses the whole path (kernel -> efs-proxy -> TLS -> EFS backend),
+        # so its latency is dominated by the backend, not the tunnel: a slow or
+        # throttled backend makes `df` block past the timeout even though the
+        # proxy is perfectly healthy. Reacting to that by SIGKILLing efs-proxy
+        # mid-RPC can leave FreeBSD's NFSv4.1 session unrecoverable (nfsbadse),
+        # wedging the next `df` in unkillable D-state - the check manufacturing
+        # the failure it then reacts to.
+        #
+        # Instead, probe the proxy directly: a live efs-proxy keeps a persistent
+        # ESTABLISHED tcp4 loopback connection to the kernel NFS client, even
+        # when the mount is idle. Only restart when the proxy is genuinely gone,
+        # confirmed by BOTH signals: no ESTABLISHED socket on its port AND the
+        # proxy process no longer running. If sockstat is unavailable we have no
+        # evidence of failure, so we do nothing rather than kill on a guess.
+        port = os.path.basename(state_file).rsplit(".", 1)[-1]
+        established = _freebsd_proxy_port_established(port)
+        state["last_stunnel_check_time"] = current_time
+
+        if established or established is None:
+            logging.debug(
+                "efs-proxy [PID: %s] for tls mount on %s passed health check "
+                "(port %s established=%s).",
+                stunnel_pid,
+                mountpoint,
+                port,
+                established,
+            )
+            rewrite_state_file(state, state_file_dir, state_file)
+            return
+
+        # No established connection on the proxy's port. Only treat this as a
+        # dead proxy if the process is also gone; a live-but-not-serving proxy
+        # (e.g. mid-reconnect) is left alone rather than SIGKILLed mid-recovery.
+        if is_mount_stunnel_proc_running(stunnel_pid, state_file, state_file_dir):
+            logging.warning(
+                "efs-proxy [PID: %s] for %s is running but has no established "
+                "connection on port %s; leaving it alone (not restarting).",
+                stunnel_pid,
+                mountpoint,
+                port,
+            )
+            rewrite_state_file(state, state_file_dir, state_file)
+            return
+
+        logging.warning(
+            "efs-proxy for %s is not running and has no established connection "
+            "on port %s, restarting a new efs-proxy process.",
+            mountpoint,
+            port,
+        )
+        send_signal_to_running_stunnel_process_group(
+            stunnel_pid, state_file, state_file_dir, SIGKILL
+        )
+        restart_tls_tunnel(child_procs, state, state_file_dir, state_file)
+        return
+
     process = subprocess.Popen(
         ["df", mountpoint],
         stdout=subprocess.DEVNULL,
