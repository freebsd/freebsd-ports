--- run.c.orig	Sun Sep  7 23:40:41 2003
+++ run.c	Sun Sep  7 23:42:04 2003
@@ -20,10 +20,15 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include "ask.h"
 #include "trsim.h"
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+
 int	assign_ok = 1;
 
 int	changed;
@@ -56,7 +61,11 @@
 {
 	if(i >= v->size) {
 	    printf("Bad index %d: only %d elements in vector!\n", i, v->size);
+#if (defined(BSD) && (BSD >= 199103))
+	    abort();
+#else
 	    abort(0);
+#endif
 	}
 	return v->ptr[i];
 }
@@ -65,7 +74,11 @@
 {
 	if(i >= v->size) {
 	    printf("Bad index %d: only %d elements in vector!\n", i, v->size);
+#if (defined(BSD) && (BSD >= 199103))
+	    abort();
+#else
 	    abort(0);
+#endif
 	}
 	return v->flags[i];
 }
