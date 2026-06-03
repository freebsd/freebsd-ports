--- src/efs_utils_common/mount_utils.py.orig	2026-04-16 15:59:37 UTC
+++ src/efs_utils_common/mount_utils.py
@@ -62,7 +62,15 @@ def mount_nfs(config, dns_name, path, mountpoint, opti
 
     nfs_options = get_nfs_mount_options(options, config)
 
-    if not check_if_platform_is_mac():
+    if sys.platform.startswith("freebsd"):
+        command = [
+            "/sbin/mount_nfs",
+            "-o",
+            nfs_options,
+            mount_path,
+            mountpoint,
+        ]
+    elif not check_if_platform_is_mac():
         command = [
             "/sbin/mount.nfs4",
             mount_path,
