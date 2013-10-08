--- extra/yassl/taocrypt/include/misc.hpp.orig
+++ extra/yassl/taocrypt/include/misc.hpp
@@ -124,7 +124,7 @@
 
 
 // no gas on these systems ?, disable for now
-#if defined(__sun__) || defined (__APPLE__)
+#if defined(__sun__) || defined (__APPLE__) || defined(__clang__)
     #define TAOCRYPT_DISABLE_X86ASM
 #endif
 
