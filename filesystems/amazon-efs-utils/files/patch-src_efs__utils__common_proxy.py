--- src/efs_utils_common/proxy.py.orig	2026-04-08 20:20:34 UTC
+++ src/efs_utils_common/proxy.py
@@ -286,7 +286,7 @@ def write_stunnel_config_file(
         # Only support in stunnel version 5.25+.
         global_config["foreground"] = "quiet"
 
-    if any(
+    if sys.platform.startswith("freebsd") or any(
         release in system_release_version
         for release in SKIP_NO_SO_BINDTODEVICE_RELEASES
     ):
@@ -586,7 +586,9 @@ def get_init_system(comm_file="/proc/1/comm"):
 
 def get_init_system(comm_file="/proc/1/comm"):
     init_system = DEFAULT_UNKNOWN_VALUE
-    if not check_if_platform_is_mac():
+    if sys.platform.startswith("freebsd"):
+        init_system = "rc"
+    elif not check_if_platform_is_mac():
         try:
             with open(comm_file) as f:
                 init_system = f.read().strip()
@@ -625,6 +627,25 @@ def start_watchdog(init_system):
         if rc != 0:
             subprocess.Popen(
                 ["systemctl", "start", WATCHDOG_SERVICE],
+                stdout=subprocess.DEVNULL,
+                stderr=subprocess.DEVNULL,
+                close_fds=True,
+            )
+        else:
+            logging.debug("%s is already running", WATCHDOG_SERVICE)
+
+    elif init_system == "rc":
+        # FreeBSD: use service(8) with onestart/onestatus so the watchdog
+        # runs even when the user hasn't enabled it in rc.conf.
+        rc = subprocess.call(
+            ["/usr/sbin/service", WATCHDOG_SERVICE, "onestatus"],
+            stdout=subprocess.DEVNULL,
+            stderr=subprocess.DEVNULL,
+            close_fds=True,
+        )
+        if rc != 0:
+            subprocess.Popen(
+                ["/usr/sbin/service", WATCHDOG_SERVICE, "onestart"],
                 stdout=subprocess.DEVNULL,
                 stderr=subprocess.DEVNULL,
                 close_fds=True,
