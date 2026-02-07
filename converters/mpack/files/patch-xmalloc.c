--- xmalloc.c.orig	Mon Jul 21 23:35:31 2003
+++ xmalloc.c	Sun Mar 26 23:07:02 2006
@@ -23,14 +23,14 @@
  * SOFTWARE.
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
-extern char *malloc(), *realloc();
 
 char *xmalloc (int size)
 {
     char *ret;
 
-    if (ret = malloc((unsigned) size))
+    if ((ret = malloc((unsigned) size)))
       return ret;
 
     fprintf(stderr, "Memory exhausted\n");
@@ -43,7 +43,7 @@
     char *ret;
 
     /* xrealloc (NULL, size) behaves like xmalloc (size), as in ANSI C */
-    if (ret = !ptr ? malloc ((unsigned) size) : realloc (ptr, (unsigned) size))
+    if ((ret = !ptr ? malloc ((unsigned) size) : realloc (ptr, (unsigned) size)))
       return ret;
 
     fprintf(stderr, "Memory exhausted\n");
