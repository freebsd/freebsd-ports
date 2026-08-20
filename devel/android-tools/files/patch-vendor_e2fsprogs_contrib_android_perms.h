--- vendor/e2fsprogs/contrib/android/perms.h.orig	2026-08-01 07:20:11.000000000 +0200
+++ vendor/e2fsprogs/contrib/android/perms.h
@@ -3,3 +3,8 @@
 
-# include <linux/types.h>
+# ifdef __FreeBSD__
+#  include <sys/types.h>
+#  include <stdint.h>
+# else
+#  include <linux/types.h>
+# endif
 # include <ext2fs/ext2fs.h>
