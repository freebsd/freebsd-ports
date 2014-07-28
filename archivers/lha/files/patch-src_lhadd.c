--- src/lhadd.c.orig	Mon Jul 31 18:09:53 2000
+++ src/lhadd.c	Mon Jul 31 18:14:20 2000
@@ -270,13 +270,35 @@
 {
 	int             old_umask;
 	FILE           *afp;
+        int             tempfd;
+
+    #ifdef TMP_FILENAME_TEMPLATE
+          if (extract_directory == NULL) {
+                  strcpy(temporary_name, TMP_FILENAME_TEMPLATE);
+          }
+          else {
+                  sprintf(temporary_name, "%s/lhXXXXXX", extract_directory);
+          }
+          tempfd = mkstemp(temporary_name);
+    #else
+    char           *p, *s;
+   
+          strcpy(temporary_name, archive_name);
+          for (p = temporary_name, s = (char *) 0; *p; p++)
+                  if (*p == '/')
+                          s = p;
+	  strcpy((s ? s + 1 : temporary_name), "lhXXXXXX");
+          tempfd = mkstemp(temporary_name);
+    #endif
+        if (tempfd == -1)
+          return NULL;
 
-	build_temporary_name();
 	signal(SIGINT, interrupt);
 	signal(SIGHUP, interrupt);
 
 	old_umask = umask(077);
-	afp = xfopen(temporary_name, WRITE_BINARY);
+	/*afp = xfopen(temporary_name, WRITE_BINARY);*/
+	afp = fdopen(tempfd, "w+");
 	remove_temporary_at_error = TRUE;
 	temporary_fp = afp;
 	umask(old_umask);
