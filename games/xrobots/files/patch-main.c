--- main.c.orig	Sat Feb 28 22:37:53 2004
+++ main.c	Sat Feb 28 22:38:30 2004
@@ -170,7 +170,7 @@
 	{"-scorefile","scorefile",XrmoptionSepArg, NULL },
 };
 
-static XtResource application_resources[] = {
+XtResource application_resources[] = {
   {"foreground", "Foreground", XtRPixel, sizeof(Pixel),
                 (Cardinal)&fg, XtRString, (caddr_t) "Black"},
   {"background", "Background", XtRPixel, sizeof(Pixel),
