--- ./main.c.orig	1991-09-13 20:32:10.000000000 +0000
+++ ./main.c	2013-05-31 10:39:59.000000000 +0000
@@ -146,21 +146,11 @@
 	{"-scorefile","scorefile",XrmoptionSepArg, NULL },
 };
 
-static XtResource application_resources[] = {
-  {"foreground", "Foreground", XtRPixel, sizeof(Pixel),
-                (Cardinal)&fg, XtRString, (caddr_t) "Black"},
-  {"background", "Background", XtRPixel, sizeof(Pixel),
-                (Cardinal)&bg, XtRString, (caddr_t) "White"},
-  {"translations","Translations", XtRTranslationTable, sizeof(XtTranslations),
-                (Cardinal)&translations, XtRString, (caddr_t)translations_str},
-  {"scorefile","Scorefile", XtRString, sizeof(String),
-                (Cardinal)&score_filename, XtRString, (caddr_t)SCORE_FILE},
-};
 
 /*----------------------------------------------------------------------*/
 
 main(argc, argv)
-  unsigned int argc;
+  int argc;
   char **argv;
 {
   Arg args[1];
@@ -168,6 +158,17 @@
   Widget quit_command,
 	 new_game_command;
 
+XtResource application_resources[] = {
+  {"foreground", "Foreground", XtRPixel, sizeof(Pixel),
+                (Cardinal)&fg, XtRString, (caddr_t) "Black"},
+  {"background", "Background", XtRPixel, sizeof(Pixel),
+                (Cardinal)&bg, XtRString, (caddr_t) "White"},
+  {"translations","Translations", XtRTranslationTable, sizeof(XtTranslations),
+                (Cardinal)&translations, XtRString, (caddr_t)translations_str},
+  {"scorefile","Scorefile", XtRString, sizeof(String),
+                (Cardinal)&score_filename, XtRString, (caddr_t)SCORE_FILE},
+};
+
   srandom(getpid());
   current_block = 0;
   current_callback = NULL;
