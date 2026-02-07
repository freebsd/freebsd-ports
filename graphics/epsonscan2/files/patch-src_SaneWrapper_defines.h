--- src/SaneWrapper/defines.h.orig	2024-09-12 07:10:44 UTC
+++ src/SaneWrapper/defines.h
@@ -33,14 +33,30 @@ typedef enum {
 } bool;
 #endif
 #include <stdlib.h>
-#define _assert(type,condition) \
+#undef _assert
+#define _assert(type,condition)			\
   if (!(condition)) \
   { \
     exit (EXIT_FAILURE); \
   }
+#ifndef __FreeBSD__
 #define require(condition) _assert ("require", condition)
 #define promise(condition) _assert ("promise", condition)
+#else
+#define require(condition) \
+  if (!(condition)) \
+  { \
+    exit (EXIT_FAILURE); \
+  }
+#define promise(condition) \
+  if (!(condition)) \
+  { \
+    exit (EXIT_FAILURE); \
+  }
+#endif
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include <stdlib.h>
 #define t_alloca(sz,t) ((t *) alloca ((sz) * sizeof (t)))
 #define t_calloc(sz,t) ((t *) calloc ((sz) , sizeof (t)))
