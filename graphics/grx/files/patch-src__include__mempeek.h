--- src/include/mempeek.h.orig
+++ src/include/mempeek.h
@@ -29,7 +29,7 @@
 #include "memmode.h"
 #endif
 
-#ifdef __GNUC__
+#if defined(__GNUC__) && !defined(__clang__)
 #include "gcc/mempeek.h"
 #elif defined(__TURBOC__)
 #include "bcc/mempeek.h"
