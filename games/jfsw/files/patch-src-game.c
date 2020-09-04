Rename PREFIX to DATADIR as its purpose is only to find data files.

--- src/game.c.orig	2020-09-03 06:19:21 UTC
+++ src/game.c
@@ -3470,9 +3470,9 @@ int app_main(int argc, char const * const argv[])
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
