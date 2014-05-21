--- mysys/default.c.orig	2013-10-01 21:15:03.544135869 +0200
+++ mysys/default.c	2013-10-01 21:15:38.871375504 +0200
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
@@ -803,6 +803,14 @@
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
@@ -1067,7 +1067,8 @@
           if (name[0] == FN_HOMELIB)	/* Add . to filenames in home */
             *end++= '.';
           strxmov(end, conf_file, *ext, " ", NullS);
-          fputs(name, stdout);
+          if (strstr(name, "/etc") != name)
+            fputs(name, stdout);
         }
       }
     }
@@ -1226,10 +1226,8 @@
   errors += add_directory(alloc, "/etc/", dirs);
   errors += add_directory(alloc, "/etc/mysql/", dirs);
 
-#if defined(DEFAULT_SYSCONFDIR)
-  if (DEFAULT_SYSCONFDIR[0])
-    errors += add_directory(alloc, DEFAULT_SYSCONFDIR, dirs);
-#endif /* DEFAULT_SYSCONFDIR */
+  errors += add_directory(alloc, "%%PREFIX%%/etc/", dirs);
+  errors += add_directory(alloc, "%%PREFIX%%/etc/mysql/", dirs);
 
 #endif
 
