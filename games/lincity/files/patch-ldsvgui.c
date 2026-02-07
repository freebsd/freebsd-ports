--- ldsvgui.c.orig	2003-10-05 05:53:32 UTC
+++ ldsvgui.c
@@ -99,8 +99,8 @@ char LIBDIR[_MAX_PATH];
 char LIBDIR[256];
 #endif
 
-char *lc_save_dir;
-char save_names[10][42];
+extern char *lc_save_dir;
+extern char save_names[10][42];
 
 /* ---------------------------------------------------------------------- *
  * Public Functions
