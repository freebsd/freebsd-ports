--- ./AppHdr.h.orig	2010-03-27 00:43:25.000000000 +0100
+++ ./AppHdr.h	2010-04-18 13:17:52.000000000 +0200
@@ -157,7 +157,7 @@
     //          setuid or setgid. Filenames passed to this command *are not
     //          validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 %s 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 %s 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
@@ -457,8 +457,8 @@
     #ifndef SAVE_PACKAGE_NONE
     #ifdef USE_TAR
       #define PACKAGE_SUFFIX ".tar.gz"
-      #define SAVE_PACKAGE_CMD "tar"
-      #define LOAD_UNPACKAGE_CMD "tar -zxf %s"PACKAGE_SUFFIX" -C %s"
+      #define SAVE_PACKAGE_CMD "gtar"
+      #define LOAD_UNPACKAGE_CMD "gtar -zxf %s"PACKAGE_SUFFIX" -C %s"
       #define UNPACK_SPECIFIC_FILE_CMD LOAD_UNPACKAGE_CMD " %s"
     #else
     #ifdef USE_ZIP
