
$FreeBSD$

--- oafd/qsort_ex.c	2001/11/07 11:18:59	1.1
+++ oafd/qsort_ex.c	2001/11/07 11:19:28
@@ -26,7 +26,7 @@
 #include <string.h>
 #include "qsort_ex.h"
 
-#if HAVE_ALLOCA
+#if HAVE_ALLOCA_H
 #include <alloca.h>
 #endif
 
