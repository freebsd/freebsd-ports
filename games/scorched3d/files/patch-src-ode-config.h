--- src/ode/config.h.orig	Wed Jul 30 17:41:29 2003
+++ src/ode/config.h	Sun Aug  3 09:07:13 2003
@@ -31,7 +31,7 @@
 
 #include <stdio.h>
 #include <stdarg.h>
-#include <malloc.h>		// for alloca under windows
+#include <stdlib.h>		// for alloca under windows
 #include <string.h>
 #include <math.h>
 
