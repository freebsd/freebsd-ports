--- mysys/default.c.orig	2012-12-17 03:57:40.000000000 +0200
+++ mysys/default.c	2012-12-17 04:00:28.000000000 +0200
@@ -89,7 +89,7 @@
 
 /* Which directories are searched for options (and in which order) */
 
-#define MAX_DEFAULT_DIRS 6
+#define MAX_DEFAULT_DIRS 7
 #define DEFAULT_DIRS_SIZE (MAX_DEFAULT_DIRS + 1)  /* Terminate with NULL */
 static const char **default_directories = NULL;
 
@@ -785,7 +785,7 @@
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -1229,6 +1229,7 @@
 #if defined(DEFAULT_SYSCONFDIR)
   if (DEFAULT_SYSCONFDIR[0])
     errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
+    errors += add_directory(alloc, DEFAULT_SYSCONFDIR "/mysql", dirs);
 #endif /* DEFAULT_SYSCONFDIR */
 
 #endif
