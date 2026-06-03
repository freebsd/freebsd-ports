--- src/efs_utils_common/mount_options.py.orig	2026-04-08 20:20:34 UTC
+++ src/efs_utils_common/mount_options.py
@@ -7,6 +7,8 @@
 # the License.
 
 
+import sys
+
 from efs_utils_common.constants import (
     AP_REGEX_PATTERN,
     MOUNT_TYPE_S3FILES,
@@ -65,6 +67,13 @@ def get_nfs_mount_options(options, config):
                     "which is not compatible with S3 Files."
                 )
             options["nfsvers"] = "4.2"
+        elif sys.platform.startswith("freebsd"):
+            # FreeBSD's mount_nfs does not recognize nfsvers=4.1; it would leave
+            # mountmode=ANY and send an NFSv3 NULL probe which EFS rejects. Use
+            # the native `nfsv4` option + `minorversion=1` so mount_nfs sets
+            # mountmode=V4 and sends a v4 NULL probe.
+            options["nfsv4"] = None
+            options["minorversion"] = "1"
         else:
             options["nfsvers"] = "4.1" if not check_if_platform_is_mac() else "4.0"
 
@@ -86,6 +95,15 @@ def get_nfs_mount_options(options, config):
         options["retrans"] = "2"
     if "noresvport" not in options:
         options["noresvport"] = None
+
+    # FreeBSD requires oneopenown for AWS EFS compatibility.
+    # retrycnt=1 matches the FreeBSD-recommended EFS mount options and avoids
+    # the default infinite retry on failure.
+    if sys.platform.startswith("freebsd"):
+        if "oneopenown" not in options:
+            options["oneopenown"] = None
+        if "retrycnt" not in options:
+            options["retrycnt"] = "1"
 
     # Set mountport to 2049 for MacOS
     if check_if_platform_is_mac():
