--- mysys/default.c.orig	Tue Jan 30 09:34:13 2007
+++ mysys/default.c	Sat Feb  3 17:12:31 2007
@@ -608,7 +608,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1013,9 +1013,9 @@
 #else
   *ptr++= "/etc/";
   *ptr++= "/etc/mysql/";
+  *ptr++= "%%PREFIX%%/etc/";
+  *ptr++= "%%PREFIX%%/etc/mysql/";
 #endif
-  if ((env= getenv(STRINGIFY_ARG(DEFAULT_HOME_ENV))))
-    *ptr++= env;
   *ptr++= "";			/* Place for defaults_extra_file */
 #if !defined(__WIN__) && !defined(__NETWARE__)
   *ptr++= "~/";;
