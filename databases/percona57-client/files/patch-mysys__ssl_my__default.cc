--- mysys_ssl/my_default.cc.orig	2016-11-27 19:44:54 UTC
+++ mysys_ssl/my_default.cc
@@ -114,7 +114,7 @@ static my_bool defaults_already_read= FA
 
 /* Which directories are searched for options (and in which order) */
 
-#define MAX_DEFAULT_DIRS 6
+#define MAX_DEFAULT_DIRS 7
 #define DEFAULT_DIRS_SIZE (MAX_DEFAULT_DIRS + 1)  /* Terminate with NULL */
 static const char **default_directories = NULL;
 
@@ -1416,7 +1416,10 @@ static const char **init_default_directo
 
 #if defined(DEFAULT_SYSCONFDIR)
   if (DEFAULT_SYSCONFDIR[0])
+  {
     errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
+    errors += add_directory(alloc, DEFAULT_SYSCONFDIR "/mysql", dirs);
+  }
 #endif /* DEFAULT_SYSCONFDIR */
 
 #endif
@@ -1488,7 +1491,7 @@ int check_file_permissions(const char *f
   MY_STAT stat_info;
 
   if (!my_stat(file_name,&stat_info,MYF(0)))
-    return 1;
+    return 0;
   /*
     Ignore .mylogin.cnf file if not exclusively readable/writable
     by current user.
