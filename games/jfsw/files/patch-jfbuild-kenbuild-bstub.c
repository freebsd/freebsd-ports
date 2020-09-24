Rename PREFIX to DATADIR as its only purpose is to access data files
(and avoid conflict with FreeBSD PREFIX, which has another meaning)

--- jfbuild/kenbuild/bstub.c.orig	2020-09-22 22:08:35 UTC
+++ jfbuild/kenbuild/bstub.c
@@ -73,9 +73,9 @@ int ExtInit(void)
 	getch();
 	*/
 
-#if defined(PREFIX)
+#if defined(DATADIR)
     {
-        const char *prefixdir = PREFIX;
+        const char *prefixdir = DATADIR;
         if (prefixdir && prefixdir[0]) {
             addsearchpath(prefixdir);
         }
