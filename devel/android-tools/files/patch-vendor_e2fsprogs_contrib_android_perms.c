--- vendor/e2fsprogs/contrib/android/perms.c	2024-08-29 19:46:57.000000000 +0200
+++ vendor/e2fsprogs/contrib/android/perms.c	2026-03-21 14:11:37.709049000 +0100
@@ -6,6 +6,22 @@
 #include "support/nls-enable.h"
 #include <time.h>
 #include <sys/stat.h>
+
+#ifdef __FreeBSD__
+#ifndef VFS_CAP_REVISION_2
+#define VFS_CAP_REVISION_2 0x02000002
+#endif
+#ifndef VFS_CAP_FLAGS_EFFECTIVE
+#define VFS_CAP_FLAGS_EFFECTIVE 0x000001
+#endif
+struct vfs_cap_data {
+	__le32 magic_etc;
+	struct {
+		__le32 permitted;
+		__le32 inheritable;
+	} data[2];
+};
+#endif
 
 #ifndef XATTR_SELINUX_SUFFIX
 # define XATTR_SELINUX_SUFFIX  "selinux"
