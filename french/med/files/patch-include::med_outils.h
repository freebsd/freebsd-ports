--- include/med_outils.h.orig	2011-07-28 15:11:41.000000000 +0200
+++ include/med_outils.h	2011-12-26 19:27:12.000000000 +0100
@@ -241,7 +241,7 @@
 
 /*Pour eviter le bug solaris*/
 #ifndef __APPLE__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 /* Interface des routines du composant tools */
