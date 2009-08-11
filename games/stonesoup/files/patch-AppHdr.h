--- ./AppHdr.h.orig	2009-07-29 01:31:27.000000000 +0200
+++ ./AppHdr.h	2009-08-03 10:10:09.000000000 +0200
@@ -126,7 +126,7 @@
     //          setuid or setgid. Filenames passed to this command *are not
     //          validated in any way*.
     //
-    // #define SOUND_PLAY_COMMAND "/usr/bin/play -v .5 %s 2>/dev/null &"
+    %%SOUND%%#define SOUND_PLAY_COMMAND "%%LOCALBASE%%/bin/play -v .5 %s 2>/dev/null &"
 
     // For cases when the game will be played on terms that don't support the
     // curses "bold == lighter" 16 colour mode. -- bwr
@@ -413,6 +413,8 @@
     // The default behaviour is to compress with zip.
     // To use GNU tar instead, define SAVE_PACKAGE_TAR.
     // To avoid compression entirely, define SAVE_PACKAGE_NONE.
+    #define SAVE_PACKAGE_NONE
+
     #ifndef SAVE_PACKAGE_NONE
     #ifdef SAVE_PACKAGE_TAR
       // The --absolute-names switch is only there to suppress noise on stdout.
