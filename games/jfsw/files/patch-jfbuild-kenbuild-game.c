Rename PREFIX to DATADIR as its only purpose is to access data files
(and avoid conflict with FreeBSD PREFIX, which has another meaning)

--- jfbuild/kenbuild/game.c.orig	2020-09-22 22:08:35 UTC
+++ jfbuild/kenbuild/game.c
@@ -405,9 +405,9 @@ int app_main(int argc, char const * const argv[])
     int startretval = STARTWIN_RUN;
     struct startwin_settings settings;
 
-#if defined(PREFIX)
+#if defined(DATADIR)
     {
-        const char *prefixdir = PREFIX;
+        const char *prefixdir = DATADIR;
         if (prefixdir && prefixdir[0]) {
             addsearchpath(prefixdir);
         }
