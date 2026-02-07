--- cpp/include/IceUtil/Config.h.orig	2021-06-21 14:44:58 UTC
+++ cpp/include/IceUtil/Config.h
@@ -78,13 +78,15 @@
     //
 #   include <stdint.h>
 
-#   if defined(__WORDSIZE) && (__WORDSIZE == 64)
+#   if (__cplusplus >= 201103L) && defined(__WORDSIZE) && (__WORDSIZE == 64)
 #      define ICE_64
-#   elif defined(__WORDSIZE) && (__WORDSIZE == 32)
+#   elif (__cplusplus >= 201103L) && defined(__WORDSIZE) && (__WORDSIZE == 32)
 #      define ICE_32
 #   elif defined(__sun) && (defined(__sparcv9) || defined(__x86_64))  || \
          defined(__linux__) && defined(__x86_64)                      || \
          defined(__APPLE__) && defined(__x86_64)                      || \
+         defined(__FreeBSD__) && defined(__x86_64)                    || \
+         defined(__FreeBSD__) && defined(__LP64__)                    || \
          defined(__hppa) && defined(__LP64__)                         || \
          defined(_ARCH_COM) && defined(__64BIT__)                     || \
          defined(__alpha__)                                           || \
