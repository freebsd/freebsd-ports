--- mysys/default.c.orig	Mon Apr 11 11:15:09 2005
+++ mysys/default.c	Mon Apr 11 11:15:23 2005
@@ -49,9 +49,7 @@
 "sys:/etc/",
 #else
 "/etc/",
-#endif
-#ifdef DATADIR
-DATADIR,
+"%%PREFIX%%/etc/",
 #endif
 "",					/* Place for defaults_extra_dir */
 #if !defined(__WIN__) && !defined(__NETWARE__)
