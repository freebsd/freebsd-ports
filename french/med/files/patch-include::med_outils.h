--- include/med_outils.h.orig	Wed Nov 17 15:05:46 2004
+++ include/med_outils.h	Sat Jan  8 22:51:32 2005
@@ -152,7 +152,7 @@
 #define MED_TAILLE_LIENS 7 
 
 /*Pour eviter le bug solaris*/
-#include <malloc.h>
+#include <stdlib.h>
 
 /* Interface des routines du composant tools */
 #include <med_misc.h>
