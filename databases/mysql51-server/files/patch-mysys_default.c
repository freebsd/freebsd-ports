--- mysys/default.c.orig	2008-08-28 17:40:47.000000000 +0200
+++ mysys/default.c	2008-09-16 08:20:23.000000000 +0200
@@ -638,7 +638,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1091,7 +1091,10 @@
 
 #if defined(DEFAULT_SYSCONFDIR)
   if (DEFAULT_SYSCONFDIR != "")
+  {
     errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
+    errors += add_directory(alloc, DEFAULT_SYSCONFDIR "/mysql", dirs);
+  }
 #endif /* DEFAULT_SYSCONFDIR */
 
 #endif
