--- source/algol68g.h.orig	2010-09-09 10:16:58.000000000 +0200
+++ source/algol68g.h	2010-09-09 09:58:41.000000000 +0200
@@ -65,12 +65,6 @@ typedef unsigned STATUS_MASK;
 #endif
 #endif
 
-#if defined ENABLE_MACOSX
-#define __off_t off_t
-#define __pid_t pid_t
-#define __mode_t mode_t
-#endif
-
 #if defined ENABLE_POSTGRESQL
 #include <libpq-fe.h>
 #endif
