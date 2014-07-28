--- ../../orig/uudeview-0.5.18/uulib/fptools.c	Wed Jun  6 14:21:47 2001
+++ uulib/fptools.c	Sun Sep  1 21:57:16 2002
@@ -507,5 +507,20 @@
 char * TOOLEXPORT
 _FP_tempnam (char *dir, char *pfx)
 {
-  return _FP_strdup (tmpnam (NULL));
+  /* TODO: should make this patch acceptable for fitting back
+   * into the standard uudeview distribution (rather than the
+   * hack that it is now). */
+
+  char *fname;
+  int fd;
+
+  if ((fname = _FP_strdup ("/tmp/uuXXXXXXX")) != NULL) {
+    if ((fd = mkstemp (fname)) != -1) {
+      close (fd);
+      return fname;
+    } else {
+      _FP_free (fname);
+    }
+  }
+  return NULL;
 }
