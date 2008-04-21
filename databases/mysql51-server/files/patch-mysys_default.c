--- mysys/default.c.orig	2008-04-08 13:23:13.000000000 +0200
+++ mysys/default.c	2008-04-21 19:20:44.000000000 +0200
@@ -623,7 +623,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1105,6 +1105,7 @@
 #ifdef DEFAULT_SYSCONFDIR
   if (DEFAULT_SYSCONFDIR != "")
     ADD_DIRECTORY(DEFAULT_SYSCONFDIR);
+    ADD_DIRECTORY(DEFAULT_SYSCONFDIR "/mysql/");
 #endif
   ADD_COMMON_DIRECTORIES();
   ADD_DIRECTORY("~/");
