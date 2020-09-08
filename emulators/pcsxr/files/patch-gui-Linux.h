--- gui/Linux.h.orig	2020-09-07 22:26:22 UTC
+++ gui/Linux.h
@@ -43,8 +43,8 @@
 
 extern gboolean UseGui;
 extern int StatesC;
-char cfgfile[MAXPATHLEN];	/* ADB Comment this out - make a local var, or at least use gchar funcs */
-char cfgfile_basename[MAXPATHLEN];	/* ADB Comment this out - make a local var, or at least use gchar funcs */
+extern char cfgfile[MAXPATHLEN];	/* ADB Comment this out - make a local var, or at least use gchar funcs */
+extern char cfgfile_basename[MAXPATHLEN];	/* ADB Comment this out - make a local var, or at least use gchar funcs */
 
 int LoadConfig();
 void SaveConfig();
