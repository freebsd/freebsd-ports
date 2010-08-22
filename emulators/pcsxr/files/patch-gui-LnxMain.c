--- gui/LnxMain.c.orig	2010-06-01 07:51:28.324517082 +0000
+++ gui/LnxMain.c	2010-06-01 08:01:34.204348317 +0000
@@ -186,6 +186,9 @@
 	gchar *currentdir;
 
 	// scan some default locations to find plugins
+	ScanPlugins("%%PREFIX%%/lib/pcsxr/");
+	ScanPlugins("%%PREFIX%%/lib/pcsxr/lib");
+	ScanPlugins("%%PREFIX%%/lib/pcsxr/config");
 	ScanPlugins("/usr/lib/games/psemu/");
 	ScanPlugins("/usr/lib/games/psemu/lib/");
 	ScanPlugins("/usr/lib/games/psemu/config/");
@@ -211,6 +214,8 @@
 	ScanPlugins(DEF_PLUGIN_DIR "/config");
 
 	// scan some default locations to find bioses
+	ScanBios("%%PREFIX%%/lib/pcsxr/");
+	ScanBios("%%PREFIX%%/lib/pcsxr/bios");
 	ScanBios("/usr/lib/games/psemu");
 	ScanBios("/usr/lib/games/psemu/bios");
 	ScanBios("/usr/lib64/games/psemu");
