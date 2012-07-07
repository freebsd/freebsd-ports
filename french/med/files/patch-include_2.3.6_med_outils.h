--- include/2.3.6/med_outils.h.orig	2011-04-13 16:19:53.000000000 +0200
+++ include/2.3.6/med_outils.h	2011-12-26 21:14:25.000000000 +0100
@@ -157,7 +157,7 @@
 
 /*Pour eviter le bug solaris*/
 #ifndef __APPLE__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 
