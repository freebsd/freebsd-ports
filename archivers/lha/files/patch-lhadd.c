--- src/lhadd.c.orig	2000-10-04 14:57:38 UTC
+++ src/lhadd.c
@@ -75,7 +75,7 @@ add_one(fp, nafp, hdr)
 
 
 /* ------------------------------------------------------------------------ */
-FILE           *
+static FILE           *
 append_it(name, oafp, nafp)
 	char           *name;
 	FILE           *oafp, *nafp;
@@ -242,11 +242,12 @@ delete(oafp, nafp)
 		b2 = strtok(NULL, "|");
 		if (need_file(b1)) {	/* skip */
 			fseek(oafp, ahdr.packed_size, SEEK_CUR);
-			if (noexec || !quiet)
+			if (noexec || !quiet) {
 				if (b2 != NULL)
 					printf("delete %s -> %s\n", b1, b2);
 				else
 					printf("delete %s\n", b1);
+			}
 		}
 		else {		/* copy */
 			if (noexec) {
@@ -270,13 +271,35 @@ build_temporary_file()
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
@@ -340,6 +363,7 @@ temporary_to_new_archive_file(new_archiv
 	remove_temporary_at_error = FALSE;
 }
 #else
+void
 temporary_to_new_archive_file(new_archive_size)
 	long            new_archive_size;
 {
