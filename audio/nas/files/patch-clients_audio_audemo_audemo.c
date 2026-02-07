--- clients/audio/audemo/audemo.c.orig	2013-10-07 17:05:48 UTC
+++ clients/audio/audemo/audemo.c
@@ -28,6 +28,7 @@
  */
 #include "config.h"
 
+#include <inttypes.h>
 #include <stdio.h>
 
 #if defined(HAVE_STDLIB_H)
@@ -913,7 +914,7 @@ okAction(Widget w, XEvent *event, String
     GlobalDataPtr   globals;
 
     /* retrieve the address of the globals from the first parameter */
-    globals = (GlobalDataPtr) atoi(params[0]);
+    globals = (GlobalDataPtr)(uintptr_t)strtoull(params[0], NULL, 0);
     saveOk(w, globals, 0);
 }
 
@@ -1198,7 +1199,7 @@ static void
 scrollProcCB(Widget w, XtPointer globalsp, XtPointer positionp)
 {
     GlobalDataPtr   globals = (GlobalDataPtr) globalsp;
-    int             position = (int) positionp;
+    intptr_t        position = (intptr_t) positionp;
     int             newVolume;
     char            buf[50];
 
@@ -1258,7 +1259,7 @@ static void
 gainScrollCB(Widget w, XtPointer globalsp, XtPointer positionp)
 {
     GlobalDataPtr   globals = (GlobalDataPtr) globalsp;
-    int             position = (int) positionp;
+    intptr_t        position = (intptr_t) positionp;
     int             newGain;
     char            buf[50];
 
@@ -1342,7 +1343,7 @@ makeSaveDialog(GlobalDataPtr g)
     MakeWidget(s->file, s->form, asciiTextWidgetClass, NULL, "filename");
 
     /* pass the address of the globals as an argument to the action */
-    sprintf(tmp, "<Key>Return: ok(%u)", (unsigned int) g);
+    sprintf(tmp, "<Key>Return: ok(%p)", g);
     XtOverrideTranslations(s->file, XtParseTranslationTable(tmp));
 
     /* file format */
