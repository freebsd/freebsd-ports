--- run.c.orig	Tue Dec  9 22:02:20 2003
+++ run.c	Tue Dec  9 22:04:51 2003
@@ -20,11 +20,15 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <math.h>
 #include "ask.h"
 #include "trsim.h"
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #define	HOMAN_030330
 #define	MERGE_TRAINS 1
 
@@ -60,7 +64,11 @@
 {
 	if(i >= v->size) {
 	    printf("Bad index %d: only %d elements in vector!\n", i, v->size);
+#if (defined(BSD) && (BSD >= 199103))
+            abort();
+#else
 	    abort(0);
+#endif
 	}
 	return v->ptr[i];
 }
@@ -69,7 +77,11 @@
 {
 	if(i >= v->size) {
 	    printf("Bad index %d: only %d elements in vector!\n", i, v->size);
+#if (defined(BSD) && (BSD >= 199103))
+            abort();
+#else
 	    abort(0);
+#endif
 	}
 	return v->flags[i];
 }
