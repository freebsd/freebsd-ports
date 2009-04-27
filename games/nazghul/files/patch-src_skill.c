--- src/skill.c	2009-04-27 10:55:05.000000000 -0500
+++ src/skill.c	2009-04-27 10:55:29.000000000 -0500
@@ -25,9 +25,11 @@
 
 #include <assert.h>
 #include <config.h>
-//#ifdef HAVE_MALLOC_H
+#ifdef HAVE_MALLOC_H
 #include <malloc.h>
-//#endif
+#else
+#include <stdlib.h>
+#endif
 #include <string.h>
 
 static void skill_del(struct skill *skill)
