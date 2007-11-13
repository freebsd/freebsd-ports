
$FreeBSD$

--- src/metaflac/operations.c.orig
+++ src/metaflac/operations.c
@@ -21,6 +21,7 @@
 #include "utils.h"
 #include "FLAC/assert.h"
 #include "FLAC/metadata.h"
+#include "share/alloc.h"
 #include "share/grabbag.h"
 #include <stdio.h>
 #include <stdlib.h>
@@ -430,8 +431,8 @@
 	}
 
 	if(
-		0 == (title_gains = (float*)malloc(sizeof(float) * num_files)) ||
-		0 == (title_peaks = (float*)malloc(sizeof(float) * num_files))
+		0 == (title_gains = (float*)safe_malloc_mul_2op_(sizeof(float), /*times*/num_files)) ||
+		0 == (title_peaks = (float*)safe_malloc_mul_2op_(sizeof(float), /*times*/num_files))
 	)
 		die("out of memory allocating space for title gains/peaks");
 
