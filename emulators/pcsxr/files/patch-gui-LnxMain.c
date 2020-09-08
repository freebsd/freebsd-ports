--- gui/LnxMain.c.orig	2020-09-07 22:26:22 UTC
+++ gui/LnxMain.c
@@ -42,6 +42,9 @@
 
 #include <X11/extensions/XTest.h>
 
+char cfgfile[MAXPATHLEN];
+char cfgfile_basename[MAXPATHLEN];
+
 enum {
 	RUN = 0,
 	RUN_CD,
@@ -187,6 +190,9 @@ static void ScanAllPlugins (void) {
 	gchar *currentdir;
 
 	// scan some default locations to find plugins
+	ScanPlugins("%%PREFIX%%/lib/pcsxr/");
+	ScanPlugins("%%PREFIX%%/lib/pcsxr/lib");
+	ScanPlugins("%%PREFIX%%/lib/pcsxr/config");
 	ScanPlugins("/usr/lib/games/psemu/");
 	ScanPlugins("/usr/lib/games/psemu/lib/");
 	ScanPlugins("/usr/lib/games/psemu/config/");
@@ -212,6 +218,8 @@ static void ScanAllPlugins (void) {
 	ScanPlugins(DEF_PLUGIN_DIR "/config");
 
 	// scan some default locations to find bioses
+	ScanBios("%%PREFIX%%/lib/pcsxr/");
+	ScanBios("%%PREFIX%%/lib/pcsxr/bios");
 	ScanBios("/usr/lib/games/psemu");
 	ScanBios("/usr/lib/games/psemu/bios");
 	ScanBios("/usr/lib64/games/psemu");
