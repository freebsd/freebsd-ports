
$FreeBSD$

--- src/metaflac/utils.c.orig
+++ src/metaflac/utils.c
@@ -18,6 +18,7 @@
 
 #include "utils.h"
 #include "FLAC/assert.h"
+#include "share/alloc.h"
 #include "share/utf8.h"
 #include <ctype.h>
 #include <stdarg.h>
@@ -64,7 +65,7 @@
 	if(nsource == 0)
 		return;
 
-	*dest = (char*)realloc(*dest, ndest + nsource + 1);
+	*dest = (char*)safe_realloc_add_3op_(*dest, ndest, /*+*/nsource, /*+*/1);
 	if(0 == *dest)
 		die("out of memory growing string");
 	strcpy((*dest)+ndest, source);
