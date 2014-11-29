--- ./galerautils/src/gu_errno.h.orig	2014-07-31 17:55:31.000000000 -0400
+++ ./galerautils/src/gu_errno.h	2014-07-31 17:56:57.000000000 -0400
@@ -1,5 +1,5 @@
 /*
- * Copyright (C) 2013 Codership Oy <info@codership.com>
+ * Copyright (C) 2014 Codership Oy <info@codership.com>
  */
 
 #ifndef GU_ERRNO_H
@@ -8,14 +8,29 @@
 #include <errno.h>
 
 #if defined(__APPLE__) || defined(__FreeBSD__)
-# define EBADFD           (ELAST+1) /* the largest errno + 1 */
-# define EREMCHG          (ELAST+2)
-# define ENOTUNIQ         (ELAST+3)
-# define ERESTART         (ELAST+4)
-# if defined(__FreeBSD__)
-#  define ENOTRECOVERABLE (ELAST+5)
-#  define ENODATA         (ELAST+6)
-# endif
+#  define GU_ELAST ELAST
+#else
+/* must be high enough to not collide with system errnos but lower than 256 */
+#  define GU_ELAST 200
+#endif
+
+#ifndef EBADFD
+#  define EBADFD          (GU_ELAST+1)
+#endif
+#ifndef EREMCHG
+#  define EREMCHG         (GU_ELAST+2)
+#endif
+#ifndef ENOTUNIQ
+#  define ENOTUNIQ        (GU_ELAST+3)
+#endif
+#ifndef ERESTART
+#  define ERESTART        (GU_ELAST+4)
+#endif
+#ifndef ENOTRECOVERABLE
+#  define ENOTRECOVERABLE (GU_ELAST+5)
+#endif
+#ifndef ENODATA
+#  define ENODATA         (GU_ELAST+6)
 #endif
 
 #endif /* GU_STR_H */
