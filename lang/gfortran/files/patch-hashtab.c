--- libiberty/hashtab.c.orig	Thu Nov 13 11:39:39 2003
+++ libiberty/hashtab.c	Thu Mar 18 19:34:34 2004
@@ -37,9 +37,9 @@
 
 #include <sys/types.h>
 
-#ifdef HAVE_STDLIB_H
+// #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
-#endif
+// #endif
 
 #ifdef HAVE_STRING_H
 #include <string.h>
