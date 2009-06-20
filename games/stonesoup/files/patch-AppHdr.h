--- ./AppHdr.h.orig	2009-06-12 12:32:16.000000000 +0200
+++ ./AppHdr.h	2009-06-19 13:54:51.000000000 +0200
@@ -124,7 +124,7 @@
     //          setuid or setgid. Filenames passed to this command *are not
     //          validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 %s 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 %s 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
@@ -401,8 +401,8 @@
     // PACKAGE_SUFFIX is used when the package file name is needed
     //
     // Comment these lines out if you want to leave the save files uncompressed.
-    #define SAVE_PACKAGE_CMD    "/usr/bin/zip -m -q -j -1 %s.zip %s.*"
-    #define LOAD_UNPACKAGE_CMD  "/usr/bin/unzip -q -o %s.zip -d %s"
+    // #define SAVE_PACKAGE_CMD    "/usr/bin/zip -m -q -j -1 %s.zip %s.*"
+    // #define LOAD_UNPACKAGE_CMD  "/usr/bin/unzip -q -o %s.zip -d %s"
 
 #ifdef SAVE_PACKAGE_CMD
     // This is used to unpack specific files from the archive.
