--- wavegain.c.orig	2020-09-25 07:55:21 UTC
+++ wavegain.c
@@ -19,20 +19,8 @@
 #include <string.h>
 #include <ctype.h>
 
-#ifdef _WIN32
-#include <io.h>
-#else
-# ifndef __MACOSX__
-#  include <sys/io.h>
-# endif
-#endif
-
 #include <fcntl.h>
 
-#ifndef __MACOSX__
-#include <malloc.h>
-#endif
-
 #include "gain_analysis.h"
 #include "i18n.h"
 #include "getopt.h"
@@ -44,6 +32,8 @@
 
 #ifdef _WIN32
 #include <windows.h>
+#else
+#include <unistd.h>
 #endif
 
 #ifdef ENABLE_RECURSIVE
@@ -57,6 +47,9 @@
 #define ROUND64(x)   ( doubletmp = (x) + Dither.Add + (Int64_t)0x001FFFFD80000000L, *(Int64_t*)(&doubletmp) - (Int64_t)0x433FFFFD80000000L )
 #endif
 
+#include <errno.h>
+static int xrename(const char *oldpath, const char *newpath);
+
 extern int          write_to_log;
 dither_t            Dither;
 double              doubletmp;
@@ -639,7 +632,14 @@ int write_gains(const char *filename, double radio_gai
 				goto exit;
 			}
     
-			if (rename(TEMP_NAME, filename) != 0) {
+                       /*
+                       * int rename(const char *old, const char *new);
+                       * In POSIX, rename will fail if the 'old' and 'new' names are on different mounted file systems.
+                       * ( From http://en.wikipedia.org/wiki/Rename_%28C%29 )
+                       * Function 'xrename' from 'normalize-0.7.6' is one clever solution
+                       */
+                       /*if (rename(TEMP_NAME, filename) != 0) {*/
+                        if (xrename(TEMP_NAME, filename) != 0) {
 				fprintf(stderr, " Error renaming '" TEMP_NAME "' to '%s' (uh-oh)\n", filename);
 				goto exit;
 			}
@@ -650,4 +650,61 @@ exit:
 	return result;
 }
 
+/* From normalize-0.7.6/nid3lib/write.c
+ * Move the file "oldpath" to "newpath", or copy and delete if they
+ * are on different filesystems.
+*/
+static int
+xrename(const char *oldpath, const char *newpath)
+{
+  FILE *in, *out;
+  char buf[4096];
+  size_t sz;
 
+  if (strcmp(oldpath, newpath) == 0)
+    return 0;
+
+#ifdef __EMX__
+  if (unlink(newpath) == -1 && errno != ENOENT)
+    return -1;
+#endif
+
+  if (rename(oldpath, newpath) == -1) {
+    if (errno == EXDEV) {
+      /* files are on different filesystems, so we have to copy */
+      if (unlink(newpath) == -1 && errno != ENOENT)
+       return -1;
+
+      in = fopen(oldpath, "rb");
+      if (in == NULL)
+       return -1;
+      out = fopen(newpath, "wb");
+      if (out == NULL) {
+       fclose(in);
+       return -1;
+      }
+
+      while ((sz = fread(buf, 1, 4096, in)) > 0)
+       fwrite(buf, 1, sz, out);
+
+      if (ferror(in) || ferror(out)) {
+       fclose(in);
+       fclose(out);
+       return -1;
+      }
+      if (fclose(in) == EOF) {
+       fclose(out);
+       return -1;
+      }
+      if (fclose(out) == EOF)
+       return -1;
+
+      if (unlink(oldpath) == -1)
+       return -1;
+    } else {
+      return -1;
+    }
+  }
+
+  return 0;
+}
