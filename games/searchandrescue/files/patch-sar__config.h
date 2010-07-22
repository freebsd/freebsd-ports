--- ./sar/config.h.orig	2010-06-03 02:05:00.000000000 +0400
+++ ./sar/config.h	2010-07-22 23:21:05.772021076 +0400
@@ -477,7 +477,7 @@
 #define SAR_DEF_LOCAL_DATA_DIR  ".SearchAndRescue"
 
 /* Global game dir */
-#define SAR_DEF_GLOBAL_DATA_DIR "/usr/share/games/searchandrescue"
+#define SAR_DEF_GLOBAL_DATA_DIR "%%LOCALBASE%%/share/searchandrescue"
 
 /* Subdirs, one of each in the local and global game dirs */
 #define SAR_DEF_AIRCRAFTS_DIR		"aircrafts"
@@ -539,7 +539,7 @@
 #ifdef __MSW__
 # define SAR_DEF_SAR_ICON_FILE		"SearchAndRescue.ico"
 #else
-# define SAR_DEF_SAR_ICON_FILE		"/usr/share/pixmaps/SearchAndRescue.xpm"
+# define SAR_DEF_SAR_ICON_FILE		"%%PREFIX%%/share/pixmaps/SearchAndRescue.xpm"
 #endif
 
 /* Standard Texture Reference Names
