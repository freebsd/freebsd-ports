
$FreeBSD$

--- src/convert.c	2001/09/10 10:08:11	1.1
+++ src/convert.c	2001/09/10 10:08:22
@@ -24,7 +24,7 @@
 #include "convert.h"
 #include "utils.h"
 
-#include <iconv.h>
+#include <giconv.h>
 #include <string.h>
 
 /*
