--- callbacks.c.orig	Wed Jun  6 09:05:30 2001
+++ callbacks.c	Wed Jun  6 09:07:03 2001
@@ -428,11 +428,12 @@
       if (!(*++q == '\n')) break;
       *q = '\0';
       if (strlen(p) > 5 && !strncmp(p, "file:", 5)) {
-	if (filetype(p + 5) == 2) {
+#ifdef HAVE_NFTW
+	if (filetype(p + 5) == 2)
 	  add_directory(p + 5);
-	} else {
+#endif
+	if (filetype(p + 5) != 2)
 	  add_file(p + 5);
-	}
       }
       p = q + 1;
     }
