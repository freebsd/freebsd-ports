--- mysys/default.c.orig	2009-05-11 14:50:54.000000000 +0200
+++ mysys/default.c	2009-05-19 07:45:53.000000000 +0200
@@ -679,7 +679,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1128,7 +1128,10 @@
 
 #if defined(DEFAULT_SYSCONFDIR)
   if (DEFAULT_SYSCONFDIR[0])
+  {
     errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
+    errors += add_directory(alloc, DEFAULT_SYSCONFDIR "/mysql", dirs);
+  }
 #endif /* DEFAULT_SYSCONFDIR */
 
 #endif
