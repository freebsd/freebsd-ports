--- mysys/my_default.cc.orig	2021-04-23 15:06:40 UTC
+++ mysys/my_default.cc
@@ -204,7 +204,7 @@ bool no_defaults = false;
 
 /* Which directories are searched for options (and in which order) */
 
-#define MAX_DEFAULT_DIRS 6
+#define MAX_DEFAULT_DIRS 7
 #define DEFAULT_DIRS_SIZE (MAX_DEFAULT_DIRS + 1) /* Terminate with NULL */
 static const char **default_directories = nullptr;
 
@@ -915,6 +915,14 @@ static int search_default_file_with_ext(Process_option
       return 1; /* Ignore wrong files */
   }
 
+  if (strstr(name, "/etc") == name)
+  {
+    fprintf(stderr,
+             "error: Config file %s in invalid location, please move to or merge with /usr/local%s\n",
+             name,name);
+      goto err;
+  }
+
   while (true) {
     auto fileline = mysql_file_getline(buff, sizeof(buff), fp, is_login_file);
     char *linebuff = fileline.get();
@@ -1300,7 +1308,8 @@ void my_print_default_files(const char *conf_file) {
             end[(strlen(end) - 1)] = ' ';
           else
             strxmov(end, conf_file, *ext, " ", NullS);
-          fputs(name, stdout);
+          if (strstr(name, "/etc") != name)
+            fputs(name, stdout);
         }
       }
     }
@@ -1640,14 +1649,9 @@ static const char **init_default_directories(MEM_ROOT 
 
 #else
 
-  errors += add_directory(alloc, "/etc/", dirs);
-  errors += add_directory(alloc, "/etc/mysql/", dirs);
+  errors += add_directory(alloc, "/usr/local/etc/", dirs);
+  errors += add_directory(alloc, "/usr/local/etc/mysql/", dirs);
 
-#if defined(DEFAULT_SYSCONFDIR)
-  if (DEFAULT_SYSCONFDIR[0])
-    errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
-#endif /* DEFAULT_SYSCONFDIR */
-
 #endif
 
   if ((env = getenv("MYSQL_HOME"))) errors += add_directory(alloc, env, dirs);
@@ -1710,7 +1714,7 @@ int check_file_permissions(const char *file_name, bool
 #if !defined(_WIN32)
   MY_STAT stat_info;
 
-  if (!my_stat(file_name, &stat_info, MYF(0))) return 1;
+  if (!my_stat(file_name, &stat_info, MYF(0))) return 0;
   /*
     Ignore .mylogin.cnf file if not exclusively readable/writable
     by current user.
