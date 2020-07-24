--- src/ptr.c.orig	2020-07-01 02:48:35 UTC
+++ src/ptr.c
@@ -10,6 +10,10 @@
  *
  */
 
+#ifdef BSD_LIKE
+#define __BSD_VISIBLE 1
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -415,6 +419,7 @@ char *ptrchr(ptr p, char c)
     return (char*)p; /* shortcut for NULL */
 }
 
+#ifdef _GNU_SOURCE
 /*
  * find last occurrence of c in p
  * return NULL if none found.
@@ -435,6 +440,7 @@ char *memrchr(char *p, int lenp, char c)
     else
 	return NULL;
 }
+#endif
 
 char *ptrrchr(ptr p, char c)
 {
