--- include/med_outils.h.orig	Tue Dec 10 19:05:22 2002
+++ include/med_outils.h	Wed Jul 23 11:37:29 2003
@@ -111,7 +111,7 @@
 #define MED_TAILLE_PROFILS 9 
 
 /*Pour eviter le bug solaris*/
-#include <malloc.h>
+#include <stdlib.h>
 
 /* Interface des routines du composant tools */
 #include <med_misc.h>
