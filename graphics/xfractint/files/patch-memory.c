--- memory.c.orig	Tue Sep  7 00:38:10 1999
+++ memory.c	Sun Dec  7 02:51:11 2003
@@ -1,12 +1,9 @@
 #include <string.h>
 #include <limits.h>
-#include <malloc.h>
 #ifndef XFRACT
 #include <io.h>
-#include <stdarg.h>
-#else
-#include <varargs.h>
 #endif
+#include <stdarg.h>
 #include <ctype.h>
 
 #include "port.h"
