--- lefty/common.h.orig	Fri Nov  5 19:56:20 2004
+++ lefty/common.h	Fri Nov  5 20:00:50 2004
@@ -53,6 +53,9 @@
 #ifdef FEATURE_CS
 #include <ast.h>
 #else
+#ifdef HAVE_SYS_TYPES_H
+#include <sys/types.h>
+#endif
 #ifdef HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
@@ -67,9 +70,6 @@
 #endif
 #ifdef HAVE_LIMITS_H
 #include <limits.h>
-#endif
-#ifdef HAVE_SYS_TYPES_H
-#include <sys/types.h>
 #endif
 #ifdef HAVE_SYS_STAT_H
 #include <sys/stat.h>
