--- pamblend.c.orig	Mon Aug 23 11:47:46 2004
+++ pamblend.c	Mon Aug 23 11:48:00 2004
@@ -12,6 +12,7 @@
 */
 
 #include <pam.h>
+#include <math.h>
 #include <shhopt.h>
 
 #define DEFAULT_TOLERANCE 6
