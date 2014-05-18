--- src/include/memfill.h.orig
+++ src/include/memfill.h
@@ -32,7 +32,7 @@
 #include "arith.h"
 #endif
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #  include "gcc/memfill.h"
 #elif defined(__TURBOC__)
 #  include "bcc/memfill.h"
