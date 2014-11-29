Rename PREFIX to DATADIR as its purpose is only to find data files.

--- src/game.c.orig	2014-11-17 19:06:17.227366945 +0100
+++ src/game.c	2014-11-17 19:06:27.493911819 +0100
@@ -3470,9 +3470,9 @@
     }
 #endif
 
-#if defined(PREFIX)
+#if defined(DATADIR)
     {
-        const char *prefixdir = PREFIX;
+        const char *prefixdir = DATADIR;
         if (prefixdir && prefixdir[0]) {
             addsearchpath(prefixdir);
         }
