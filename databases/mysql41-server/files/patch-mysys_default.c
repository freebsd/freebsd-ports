--- mysys/default.c.orig	Fri Apr  8 10:48:24 2005
+++ mysys/default.c	Fri Apr  8 10:53:25 2005
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
