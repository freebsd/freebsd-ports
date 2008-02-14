--- mysys/default.c.orig	2008-01-29 22:41:43.000000000 +0100
+++ mysys/default.c	2008-02-14 11:03:21.000000000 +0100
@@ -623,7 +623,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1102,6 +1102,8 @@
   bzero((char *) default_directories, sizeof(default_directories));
   ADD_DIRECTORY("/etc/");
   ADD_DIRECTORY("/etc/mysql/");
+  ADD_DIRECTORY("%%PREFIX%%/etc/");
+  ADD_DIRECTORY("%%PREFIX%%/etc/mysql/");
 #ifdef DEFAULT_SYSCONFDIR
   if (DEFAULT_SYSCONFDIR != "")
     ADD_DIRECTORY(DEFAULT_SYSCONFDIR);
