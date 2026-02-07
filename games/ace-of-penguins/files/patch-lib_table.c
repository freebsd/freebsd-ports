--- lib/table.c.orig	2020-08-27 17:10:12 UTC
+++ lib/table.c
@@ -57,7 +57,7 @@ static int ex=0, ey=0, ew=0, eh=0;
 static int graphics_disabled = 1;
 
 OptionDesc *app_options;
-OptionDesc *xwin_options;
+extern OptionDesc *xwin_options;
 static OptionDesc *options[5];
 
 static OptionDesc ace_options[] = {
