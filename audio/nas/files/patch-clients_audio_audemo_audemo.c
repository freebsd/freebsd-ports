--- clients/audio/audemo/audemo.c	Sun Jun 20 15:06:50 2004
+++ clients/audio/audemo/audemo.c	Mon Oct 10 11:12:15 2005
@@ -29,4 +29,5 @@
 #include "config.h"
 
+#include <inttypes.h>
 #include <stdio.h>
 
@@ -973,5 +973,5 @@
 
     /* retrieve the address of the globals from the first parameter */
-    globals = (GlobalDataPtr) atoi(params[0]);
+    globals = (GlobalDataPtr)(uintptr_t)strtoull(params[0], NULL, 0);
     saveOk(w, globals, 0);
 }
@@ -1296,5 +1296,5 @@
 {
     GlobalDataPtr   globals = (GlobalDataPtr) globalsp;
-    int             position = (int) positionp;
+    intptr_t        position = (intptr_t) positionp;
     int             newVolume;
     char            buf[50];
@@ -1363,5 +1363,5 @@
 {
     GlobalDataPtr   globals = (GlobalDataPtr) globalsp;
-    int             position = (int) positionp;
+    intptr_t        position = (intptr_t) positionp;
     int             newGain;
     char            buf[50];
@@ -1457,5 +1457,5 @@
 
     /* pass the address of the globals as an argument to the action */
-    sprintf(tmp, "<Key>Return: ok(%u)", (unsigned int) g);
+    sprintf(tmp, "<Key>Return: ok(%p)", g);
     XtOverrideTranslations(s->file, XtParseTranslationTable(tmp));
 
