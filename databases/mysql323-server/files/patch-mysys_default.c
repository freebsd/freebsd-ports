--- mysys/default.c.orig	Mon Apr 11 10:56:31 2005
+++ mysys/default.c	Mon Apr 11 10:57:04 2005
@@ -50,9 +50,7 @@
 "C:/",
 #else
 "/etc/",
-#endif
-#ifdef DATADIR
-DATADIR,
+"%%PREFIX%%/etc/",
 #endif
 "",					/* Place for defaults_extra_dir */
 #ifndef __WIN__
