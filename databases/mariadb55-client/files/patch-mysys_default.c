--- mysys/default.c.orig	2017-04-30 11:09:31 UTC
+++ mysys/default.c
@@ -89,7 +89,7 @@ static my_bool defaults_already_read= FA
 
 /* Which directories are searched for options (and in which order) */
 
-#define MAX_DEFAULT_DIRS 6
+#define MAX_DEFAULT_DIRS 7
 #define DEFAULT_DIRS_SIZE (MAX_DEFAULT_DIRS + 1)  /* Terminate with NULL */
 static const char **default_directories = NULL;
 
@@ -786,7 +786,7 @@ static int search_default_file_with_ext(
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -804,6 +804,14 @@ static int search_default_file_with_ext(
   if (!(fp= mysql_file_fopen(key_file_cnf, name, O_RDONLY, MYF(0))))
     return 1;					/* Ignore wrong files */
 
+  if (strstr(name, "/etc") == name)
+  {
+    fprintf(stderr,
+	      "error: Config file %s in invalid location, please move to or merge with %%PREFIX%%%s\n",
+	      name,name);
+      goto err;
+  }
+
   while (mysql_file_fgets(buff, sizeof(buff) - 1, fp))
   {
     line++;
@@ -1068,7 +1076,8 @@ void my_print_default_files(const char *
           if (name[0] == FN_HOMELIB)	/* Add . to filenames in home */
             *end++= '.';
           strxmov(end, conf_file, *ext, " ", NullS);
-          fputs(name, stdout);
+          if (strstr(name, "/etc") != name)
+            fputs(name, stdout);
         }
       }
     }
@@ -1227,10 +1236,8 @@ static const char **init_default_directo
   errors += add_directory(alloc, "/etc/", dirs);
   errors += add_directory(alloc, "/etc/mysql/", dirs);
 
-#if defined(DEFAULT_SYSCONFDIR)
-  if (DEFAULT_SYSCONFDIR[0])
-    errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
-#endif /* DEFAULT_SYSCONFDIR */
+  errors += add_directory(alloc, "%%PREFIX%%/etc/", dirs);
+  errors += add_directory(alloc, "%%PREFIX%%/etc/mysql/", dirs);
 
 #endif
 
