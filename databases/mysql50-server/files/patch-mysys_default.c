--- mysys/default.c.orig	2009-04-16 13:49:52.000000000 +0200
+++ mysys/default.c	2009-05-12 07:54:11.000000000 +0200
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
   if (DEFAULT_SYSCONFDIR[0])
+  {
     errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
+    errors += add_directory(alloc, DEFAULT_SYSCONFDIR "/mysql", dirs);
+  }
 #endif /* __EMX__ || __OS2__ */
 
 #endif
