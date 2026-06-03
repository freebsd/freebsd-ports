--- src/watchdog/__init__.py.orig	2026-04-17 08:53:05 UTC
+++ src/watchdog/__init__.py
@@ -60,7 +60,7 @@ FS_PREFIX = "fs-"
 SERVICE = "elasticfilesystem"
 FS_PREFIX = "fs-"
 
-CONFIG_FILE = "/etc/amazon/efs/efs-utils.conf"
+CONFIG_FILE = "/usr/local/etc/amazon/efs/efs-utils.conf"
 CONFIG_SECTION = "mount-watchdog"
 MOUNT_CONFIG_SECTION = "mount"
 CLIENT_INFO_SECTION = "client-info"
@@ -79,7 +79,7 @@ EFS_SERVICE_NAME = "elasticfilesystem"
 
 DEFAULT_NFS_PORT = "2049"
 EFS_SERVICE_NAME = "elasticfilesystem"
-PRIVATE_KEY_FILE = "/etc/amazon/efs/privateKey.pem"
+PRIVATE_KEY_FILE = "/usr/local/etc/amazon/efs/privateKey.pem"
 DEFAULT_REFRESH_SELF_SIGNED_CERT_INTERVAL_MIN = 60
 DEFAULT_STUNNEL_HEALTH_CHECK_INTERVAL_MIN = 5
 DEFAULT_STUNNEL_HEALTH_CHECK_TIMEOUT_SEC = 30
@@ -742,7 +742,64 @@ def get_current_local_nfs_mounts(mount_file="/proc/mou
     """
     mounts = []
 
-    if not check_if_running_on_macos():
+    if sys.platform.startswith("freebsd"):
+        # FreeBSD: no /proc/mounts, and neither mount(8) nor nfsstat(8) exposes
+        # the NFS client's TCP port. Use the watchdog's own state files as the
+        # source of truth: each mount created by mount.efs has a state file
+        #   fs-<id>.<mountpoint-with-slashes-as-dots>.<port>
+        # in STATE_FILE_DIR. Cross-check with `mount -t nfs` so we skip state
+        # files whose mountpoint has already been unmounted. Keying off the
+        # state file (not the live proxy) lets the watchdog notice a dead
+        # efs-proxy and restart it.
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
+            seen = set()
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
+                if mp not in live_mps or (mp, port) in seen:
+                    continue
+                seen.add((mp, port))
+                mounts.append(
+                    Mount._make(
+                        ["127.0.0.1:/", mp, "nfs", "port=" + port, 0, 0]
+                    )
+                )
+    elif not check_if_running_on_macos():
         with open(mount_file) as f:
             for mount in f:
                 try:
