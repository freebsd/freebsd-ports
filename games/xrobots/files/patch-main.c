--- main.c.orig	Thu Jan 22 06:34:05 1998
+++ main.c	Sat Feb 28 03:53:04 2004
@@ -170,25 +170,25 @@
 	{"-scorefile","scorefile",XrmoptionSepArg, NULL },
 };
 
-static XtResource application_resources[] = {
+XtResource application_resources[] = {
   {"foreground", "Foreground", XtRPixel, sizeof(Pixel),
-                (Cardinal)&fg, XtRString, (caddr_t) "Black"},
+                NULL, XtRString, (caddr_t) "Black"},
   {"background", "Background", XtRPixel, sizeof(Pixel),
-                (Cardinal)&bg, XtRString, (caddr_t) "White"},
+                NULL, XtRString, (caddr_t) "White"},
   {"spiffy", "Spiffy", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&spiffy, XtRString, (caddr_t) "True"},
+                NULL, XtRString, (caddr_t) "True"},
   {"autoteleport", "Autoteleport", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&autoteleport, XtRString, (caddr_t) "False"},
+                NULL, XtRString, (caddr_t) "False"},
   {"autoteleportalways", "Autoteleportalways", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&autoteleportalways, XtRString, (caddr_t) "False"},
+                NULL, XtRString, (caddr_t) "False"},
   {"showmovement", "Showmovement", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&showjumps, XtRString, (caddr_t) "True"},
+                NULL, XtRString, (caddr_t) "True"},
   {"diewaiting", "Diewaiting", XtRBoolean, sizeof(Boolean),
-                (Cardinal)&diewaiting, XtRString, (caddr_t) "False"},
+                NULL, XtRString, (caddr_t) "False"},
   {"translations","Translations", XtRTranslationTable, sizeof(XtTranslations),
-                (Cardinal)&translations, XtRString, (caddr_t)translations_str},
+                NULL, XtRString, (caddr_t)translations_str},
   {"scorefile","Scorefile", XtRString, sizeof(String),
-                (Cardinal)&score_filename, XtRString, (caddr_t)SCORE_FILE},
+                NULL, XtRString, (caddr_t)SCORE_FILE},
 };
 
 /*----------------------------------------------------------------------*/
@@ -205,6 +205,16 @@
 	 new_game_command;
 
   srandom(getpid());
+
+  application_resources[0].resource_offset=(Cardinal)&fg;
+  application_resources[1].resource_offset=(Cardinal)&bg;
+  application_resources[2].resource_offset=(Cardinal)&spiffy;
+  application_resources[3].resource_offset=(Cardinal)&autoteleport;
+  application_resources[4].resource_offset=(Cardinal)&autoteleportalways;
+  application_resources[5].resource_offset=(Cardinal)&showjumps;
+  application_resources[6].resource_offset=(Cardinal)&diewaiting;
+  application_resources[7].resource_offset=(Cardinal)&translations;
+  application_resources[8].resource_offset=(Cardinal)&score_filename;
 
   top_shell = XtInitialize(argv[0], "xrobots", options, XtNumber(options),
   (int *)&argc, argv);
