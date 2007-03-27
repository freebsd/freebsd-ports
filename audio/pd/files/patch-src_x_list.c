--- src/x_list.c.orig	Fri Nov  3 05:22:20 2006
+++ src/x_list.c	Sun Mar 25 01:34:15 2007
@@ -7,7 +7,8 @@
 #ifdef MSW
 #include <malloc.h>
 #else
-#include <alloca.h>
+#include <stdlib.h>
+/*#include <alloca.h>*/
 #endif
 
 extern t_pd *newest;
