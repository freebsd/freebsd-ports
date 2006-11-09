--- cbind.c.orig	Fri May 19 17:17:06 1995
+++ cbind.c	Mon Dec 23 08:38:17 2002
@@ -6,7 +6,7 @@
 #include <sys/types.h>
 #include <string.h>
 #include <unistd.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #undef NULL
 #define NULL			0
