--- src/libsphinx2/linklist.c.orig	2007-12-06 18:25:48.000000000 +0100
+++ src/libsphinx2/linklist.c	2007-12-06 18:27:00.000000000 +0100
@@ -81,7 +81,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 
 #include "s2types.h"
 
@@ -132,7 +131,7 @@
 	cpp = list[i].freelist = (void **) malloc (list[i].n_malloc * elem_size);
 	cp = (void *) cpp;
 	for (j = list[i].n_malloc-1; j > 0; --j) {
-	    (char*)cp += elem_size;
+	    cp += elem_size;
 	    *cpp = cp;
 	    cpp = (void **)cp;
 	}
