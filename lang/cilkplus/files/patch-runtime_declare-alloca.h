--- runtime/declare-alloca.h.orig	2016-06-01 19:59:38 UTC
+++ runtime/declare-alloca.h
@@ -53,10 +53,14 @@
  * be wrong. Here's a variant on what's recommended in the autoconf doc
  */
 
+#include <sys/param.h>
+
 #if defined _MSC_VER
 #   include <malloc.h>
 #   define alloca _alloca
-#elif defined HAVE_ALLOCA_H
+#elif defined BSD4_4
+#   include <stdlib.h>
+#elif defined HAVE_ALLOCA_H 
 #   include <alloca.h>
 #elif defined __GNUC__
 #   define alloca __builtin_alloca
