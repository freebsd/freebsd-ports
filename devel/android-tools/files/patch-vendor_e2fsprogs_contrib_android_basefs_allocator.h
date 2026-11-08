--- vendor/e2fsprogs/contrib/android/basefs_allocator.h.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/e2fsprogs/contrib/android/basefs_allocator.h
@@ -4,3 +4,8 @@
 # include <time.h>
-# include <linux/types.h>
+# ifdef __FreeBSD__
+#  include <sys/types.h>
+#  include <stdint.h>
+# else
+#  include <linux/types.h>
+# endif
 # include <ext2fs/ext2fs.h>
