--- src/main.c.orig	Sun Apr 15 16:27:51 2001
+++ src/main.c	Thu May 30 23:14:44 2002
@@ -17,7 +17,7 @@
 #include <tree.h> /* libxml */
 
 #ifdef __FreeBSD__
-#include <floatingpoint.h>
+#include <ieeefp.h>
 #endif
 
 #include "sodipodi-private.h"
@@ -357,7 +357,7 @@
 
 	}
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && defined(__i386__)
 	fpresetsticky(FP_X_DZ|FP_X_INV);
 	fpsetmask(FP_X_DZ|FP_X_INV);
 #endif
