--- mysys/default.c.orig	Thu May 26 15:26:56 2005
+++ mysys/default.c	Fri Jun  3 17:16:59 2005
@@ -517,7 +517,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -867,9 +867,8 @@
     *ptr++= env;
 #endif
   *ptr++= "/etc/";
+  *ptr++= "%%PREFIX%%/etc/";
 #endif
-  if ((env= getenv(STRINGIFY_ARG(DEFAULT_HOME_ENV))))
-    *ptr++= env;
   *ptr++= "";			/* Place for defaults_extra_file */
 #if !defined(__WIN__) && !defined(__NETWARE__)
   *ptr++= "~/";;
