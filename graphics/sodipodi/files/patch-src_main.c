--- src/main.c.orig	Sun Feb  8 08:42:01 2004
+++ src/main.c	Thu Nov 25 15:25:34 2004
@@ -27,7 +27,8 @@
 #endif
 
 #ifdef __FreeBSD__
-#include <floatingpoint.h>
+#include <sys/types.h>
+#include <ieeefp.h>
 #endif
 #include <string.h>
 #include <signal.h>
@@ -216,7 +217,7 @@
 		result = sp_main_console (argc, argv);
 	}
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && defined(__i386__)
 	fpresetsticky(FP_X_DZ|FP_X_INV);
 	fpsetmask(FP_X_DZ|FP_X_INV);
 #endif
