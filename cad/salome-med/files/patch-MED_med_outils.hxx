--- src/MEDWrapper/V2_1/Core/med_outils.hxx.orig	2009-06-03 16:46:04.000000000 +0700
+++ src/MEDWrapper/V2_1/Core/med_outils.hxx	2009-06-03 16:49:05.000000000 +0700
@@ -118,7 +118,8 @@
 #define MED_TAILLE_PROFILS 9 
 
 /*Pour eviter le bug solaris*/
-#include <malloc.h>
+#include <stdlib.h>
+#include <string.h>
 
 /* Interface des routines du composant tools */
 #include "med_misc.hxx"
