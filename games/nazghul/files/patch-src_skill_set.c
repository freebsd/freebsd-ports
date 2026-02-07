--- src/skill_set.c	2009-04-27 10:56:19.000000000 -0500
+++ src/skill_set.c	2009-04-27 10:56:37.000000000 -0500
@@ -27,6 +27,8 @@
 #include <config.h>
 #ifdef HAVE_MALLOC_H
 #include <malloc.h>
+#else
+#include <stdlib.h>
 #endif
 #include <string.h>
 
