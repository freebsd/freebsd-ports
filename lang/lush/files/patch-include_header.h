--- include/header.h.orig	Thu Sep 25 23:54:56 2003
+++ include/header.h	Sun Dec 28 01:27:32 2003
@@ -45,6 +45,9 @@
 #endif
 #endif
 
+#ifdef HAVE_SYS_TYPES_H
+# include <sys/types.h>
+#endif
 
 /* VERSION.H --------------------------------------------------- */
 
