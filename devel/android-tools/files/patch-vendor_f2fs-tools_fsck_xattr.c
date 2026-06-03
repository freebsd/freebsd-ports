--- vendor/f2fs-tools/fsck/xattr.c	2024-08-29 19:46:57.000000000 +0200
+++ vendor/f2fs-tools/fsck/xattr.c	2026-03-21 14:11:45.643441000 +0100
@@ -16,6 +16,10 @@
 #include "fsck.h"
 #include "node.h"
 #include "xattr.h"
+
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 void *read_all_xattrs(struct f2fs_sb_info *sbi, struct f2fs_node *inode,
 			bool sanity_check)
