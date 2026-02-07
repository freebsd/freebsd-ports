--- src/include/memcopy.h.orig
+++ src/include/memcopy.h
@@ -44,7 +44,7 @@
 #define CPSIZE_h     sizeof(GR_int64)
 #endif
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #  include "gcc/memcopy.h"
 #elif defined(__TURBOC__)
 #  include "bcc/memcopy.h"
