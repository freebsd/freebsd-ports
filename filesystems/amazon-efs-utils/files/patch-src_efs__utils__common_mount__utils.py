--- src/efs_utils_common/mount_utils.py.orig
+++ src/efs_utils_common/mount_utils.py
@@ -65,7 +65,15 @@ def mount_nfs(config, dns_name, path, mountpoint, options, fallback_ip_address=N
 
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
