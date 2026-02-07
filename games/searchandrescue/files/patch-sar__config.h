--- ./sar/config.h.orig	2011-04-03 16:12:49.000000000 -0300
+++ ./sar/config.h	2011-08-11 20:34:05.000000000 -0300
@@ -493,7 +493,7 @@
 #define SAR_DEF_LOCAL_DATA_DIR  ".SearchAndRescue"
 
 /* Global game dir */
-#define SAR_DEF_GLOBAL_DATA_DIR "/usr/share/games/searchandrescue"
+#define SAR_DEF_GLOBAL_DATA_DIR "/usr/local/share/searchandrescue"
 
 /* Subdirs, one of each in the local and global game dirs */
 #define SAR_DEF_AIRCRAFTS_DIR		"aircrafts"
@@ -555,7 +555,7 @@
 #ifdef __MSW__
 # define SAR_DEF_SAR_ICON_FILE		"SearchAndRescue.ico"
 #else
-# define SAR_DEF_SAR_ICON_FILE		"/usr/share/pixmaps/SearchAndRescue.xpm"
+# define SAR_DEF_SAR_ICON_FILE		"/usr/local/share/pixmaps/SearchAndRescue.xpm"
 #endif
 
 /* Standard Texture Reference Names
