
$FreeBSD$

--- ces/unicode-1-1-utf-7.c	2002/03/17 11:20:12	1.1
+++ ces/unicode-1-1-utf-7.c	2002/03/17 11:20:21
@@ -33,7 +33,7 @@
 #include <stdlib.h>
 
 #define ICONV_INTERNAL
-#include <iconv.h>
+#include <biconv.h>
 
 static inline int
 lackofbytes(int bytes, size_t *bytesleft)
