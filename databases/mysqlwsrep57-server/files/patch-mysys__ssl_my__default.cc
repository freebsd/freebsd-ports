--- mysys_ssl/my_default.cc.orig	2019-10-21 05:21:41 UTC
+++ mysys_ssl/my_default.cc
@@ -132,7 +132,7 @@ char wsrep_defaults_group_suffix[FN_EXTLEN]={0,};
 #endif /* WITH_WREP */
 /* Which directories are searched for options (and in which order) */
 
-#define MAX_DEFAULT_DIRS 6
+#define MAX_DEFAULT_DIRS 7
 #define DEFAULT_DIRS_SIZE (MAX_DEFAULT_DIRS + 1)  /* Terminate with NULL */
 static const char **default_directories = NULL;
 
@@ -948,6 +948,14 @@ static int search_default_file_with_ext(Process_option
     strncpy(wsrep_defaults_file, name, sizeof(wsrep_defaults_file) - 1);
 #endif /* WITH_WSREP */
 
+  if (strstr(name, "/etc") == name)
+  {
+    fprintf(stderr,
+             "error: Config file %s in invalid location, please move to or merge with /usr/local%s\n",
+             name,name);
+      goto err;
+  }
+
   while (mysql_file_getline(buff, sizeof(buff) - 1, fp, is_login_file))
   {
     line++;
@@ -1286,7 +1294,8 @@ void my_print_default_files(const char *conf_file)
             end[(strlen(end)-1)] = ' ';
           else
             strxmov(end, conf_file, *ext , " ",  NullS);
-          fputs(name, stdout);
+          if (strstr(name, "/etc") != name)
+            fputs(name, stdout);
         }
       }
     }
@@ -1445,14 +1454,9 @@ static const char **init_default_directories(MEM_ROOT 
 
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
 
   if ((env= getenv("MYSQL_HOME")))
@@ -1522,7 +1526,7 @@ int check_file_permissions(const char *file_name, my_b
   MY_STAT stat_info;
 
   if (!my_stat(file_name,&stat_info,MYF(0)))
-    return 1;
+    return 0;
   /*
     Ignore .mylogin.cnf file if not exclusively readable/writable
     by current user.
