--- mysys/default.c.orig	Mon Apr 11 11:17:07 2005
+++ mysys/default.c	Mon Apr 11 11:27:25 2005
@@ -703,9 +703,8 @@
   *ptr++= "sys:/etc/";
 #else
   *ptr++= "/etc/";
+  *ptr++= "%%PREFIX%%/etc/";
 #endif
-  if ((env= getenv(STRINGIFY_ARG(DEFAULT_HOME_ENV))))
-    *ptr++= env;
   *ptr++= "";			/* Place for defaults_extra_file */
 #if !defined(__WIN__) && !defined(__NETWARE__)
   *ptr++= "~/";;
