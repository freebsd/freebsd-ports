--- mysys/default.c.orig	2008-08-04 14:19:45.000000000 +0200
+++ mysys/default.c	2008-08-27 12:23:54.000000000 +0200
@@ -634,7 +634,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1084,7 +1084,10 @@
     errors += add_directory(alloc, env, dirs);
 #elif defined(DEFAULT_SYSCONFDIR)
   if (DEFAULT_SYSCONFDIR != "")
+  {
     errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
+    errors += add_directory(alloc, DEFAULT_SYSCONFDIR "/mysql", dirs);
+  }
 #endif /* __EMX__ || __OS2__ */
 
 #endif
