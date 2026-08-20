--- vendor/e2fsprogs/contrib/android/fsmap.h.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/e2fsprogs/contrib/android/fsmap.h
@@ -10,3 +10,5 @@
 # include <sys/types.h>
-# include <linux/types.h>
+# ifndef __FreeBSD__
+#  include <linux/types.h>
+# endif
 # include <ext2fs/ext2fs.h>
