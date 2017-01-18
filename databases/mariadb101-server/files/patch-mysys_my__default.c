--- mysys/my_default.c.orig	2017-01-17 19:38:25 UTC
+++ mysys/my_default.c
@@ -785,7 +785,7 @@ static int search_default_file_with_ext(
   {
     MY_STAT stat_info;
     if (!my_stat(name,&stat_info,MYF(0)))
-      return 1;
+      return 0;
     /*
       Ignore world-writable regular files.
       This is mainly done to protect us to not read a file created by
@@ -803,6 +803,22 @@ static int search_default_file_with_ext(
   if (!(fp= mysql_file_fopen(key_file_cnf, name, O_RDONLY, MYF(0))))
     return 1;					/* Ignore wrong files */
 
+  if (strstr(name, "/etc") == name)
+  {
+    fprintf(stderr,
+             "error: Config file %s in invalid location, please move to or merge with /usr/local%s\n",
+             name,name);
+      goto err;
+  }
+
+  if (strstr(name, "/etc") == name)
+  {
+    fprintf(stderr,
+             "error: Config file %s in invalid location, please move to or merge with /usr/local%s\n",
+             name,name);
+      goto err;
+  }
+
   while (mysql_file_fgets(buff, sizeof(buff) - 1, fp))
   {
     line++;
@@ -1067,7 +1083,8 @@ void my_print_default_files(const char *
           if (name[0] == FN_HOMELIB)	/* Add . to filenames in home */
             *end++= '.';
           strxmov(end, conf_file, *ext, " ", NullS);
-          fputs(name, stdout);
+          if (strstr(name, "/etc") != name)
+              fputs(name, stdout);
         }
       }
     }
@@ -1228,13 +1245,10 @@ static const char **init_default_directo
 
 #else
 
-#if defined(DEFAULT_SYSCONFDIR)
-  if (DEFAULT_SYSCONFDIR[0])
-    errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
-#else
   errors += add_directory(alloc, "/etc/", dirs);
   errors += add_directory(alloc, "/etc/mysql/", dirs);
-#endif /* DEFAULT_SYSCONFDIR */
+  errors += add_directory(alloc, "/usr/local/etc/", dirs);
+  errors += add_directory(alloc, "/usr/local/etc/mysql/", dirs);
 
 #endif
 
