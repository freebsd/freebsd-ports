--- xmalloc.c.orig	2016-02-06 23:25:26.000000000 +0100
+++ xmalloc.c	2016-02-06 23:38:08.189826000 +0100
@@ -19,6 +19,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 
 #include "log.h"
 #include "xmalloc.h"
@@ -58,7 +59,7 @@ xreallocarray(void *ptr, size_t nmemb, s
 
 	if (nmemb == 0 || size == 0)
 		fatal("xreallocarray: zero size");
-	new_ptr = reallocarray(ptr, nmemb, size);
+	new_ptr = realloc(ptr, nmemb * size); /* this lacks overflow check */
 	if (new_ptr == NULL)
 		fatal("xreallocarray: allocating %zu * %zu bytes: %s",
 		    nmemb, size, strerror(errno));
