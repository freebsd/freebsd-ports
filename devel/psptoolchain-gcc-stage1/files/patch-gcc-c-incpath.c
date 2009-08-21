--- gcc/c-incpath.c.orig	2005-06-25 03:02:01.000000000 +0100
+++ gcc/c-incpath.c	2006-05-07 13:27:40.000000000 +0100
@@ -331,13 +331,18 @@
   cpp_dir *p;
 
 #if defined (HAVE_DOS_BASED_FILE_SYSTEM)
-  /* Convert all backslashes to slashes.  The native CRT stat()
-     function does not recognize a directory that ends in a backslash
-     (unless it is a drive root dir, such "c:\").  Forward slashes,
-     trailing or otherwise, cause no problems for stat().  */
-  char* c;
-  for (c = path; *c; c++)
-    if (*c == '\\') *c = '/';
+  /* Remove unnecessary trailing slashes.  On some versions of MS
+     Windows, trailing  _forward_ slashes cause no problems for stat().
+     On newer versions, stat() does not recognise a directory that ends
+     in a '\\' or '/', unless it is a drive root dir, such as "c:/",
+     where it is obligatory.  */
+  int pathlen = strlen (path);
+  char* end = path + pathlen - 1;
+  /* Preserve the lead '/' or lead "c:/".  */
+  char* start = path + (pathlen > 2 && path[1] == ':' ? 3 : 1);
+   
+  for (; end > start && IS_DIR_SEPARATOR (*end); end--)
+    *end = 0;
 #endif
 
   p = xmalloc (sizeof (cpp_dir));
