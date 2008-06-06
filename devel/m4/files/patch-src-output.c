--- src/output.c.orig	2007-07-05 03:56:06.000000000 +0000
+++ src/output.c	2007-12-12 03:48:25.000000000 +0000
@@ -254,2 +254,8 @@
 	      "Warning: cannot protect diversion across forks"));
+  /* POSIX states that it is undefined whether an append stream starts
+   * at offset 0 or at the end.  We want the beginning.
+   */
+  else if (fseeko (file, 0, SEEK_SET) != 0)
+    M4ERROR ((EXIT_FAILURE, errno,
+	     "cannot seek to beginning of diversion"));
   return file;
