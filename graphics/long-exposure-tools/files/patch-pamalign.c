--- pamalign.c.orig	Mon Aug 23 11:48:10 2004
+++ pamalign.c	Mon Aug 23 11:48:29 2004
@@ -12,6 +12,7 @@
 */
 
 #include <pam.h>
+#include <math.h>
 #include <shhopt.h>
 
 #define DEFAULT_MAXSHIFT 5
