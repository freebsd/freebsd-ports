--- run.c.orig	Fri Jul 18 15:53:36 2003
+++ run.c	Fri Jul 18 15:56:59 2003
@@ -20,9 +20,13 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "ask.h"
 #include "trsim.h"
+
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 int	assign_ok = 1;
 
@@ -56,7 +60,11 @@
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
@@ -65,7 +73,11 @@
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
