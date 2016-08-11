--- src/libsphinx2/linklist.c.orig	2001-12-13 21:11:22 UTC
+++ src/libsphinx2/linklist.c
@@ -81,7 +81,6 @@
 
 #include <stdio.h>
 #include <stdlib.h>
-#include <malloc.h>
 
 #include "s2types.h"
 
@@ -132,7 +131,7 @@ void *listelem_alloc (int32 elem_size)
 	cpp = list[i].freelist = (void **) malloc (list[i].n_malloc * elem_size);
 	cp = (void *) cpp;
 	for (j = list[i].n_malloc-1; j > 0; --j) {
-	    (char*)cp += elem_size;
+	    cp += elem_size;
 	    *cpp = cp;
 	    cpp = (void **)cp;
 	}
