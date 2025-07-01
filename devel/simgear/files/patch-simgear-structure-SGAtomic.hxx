Work around:

SGAtomic.cxx:48:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]

to fix build on i386 as Simgear uses CMAKE_CXX_STANDARD=17

--- simgear/structure/SGAtomic.hxx.orig	2025-06-30 15:01:54 UTC
+++ simgear/structure/SGAtomic.hxx
@@ -25,7 +25,7 @@
     defined(__x86_64__)
 // No need to include something. Is a Compiler API ...
 # define SGATOMIC_USE_GCC4_BUILTINS
-#elif defined(__GNUC__) && defined(__i386__)
+#elif (__cplusplus < 201703L) && defined(__GNUC__) && defined(__i386__)
 # define SGATOMIC_USE_LIBRARY_FUNCTIONS
 #elif defined(__sgi) && defined(_COMPILER_VERSION) && (_COMPILER_VERSION>=730)
 // No need to include something. Is a Compiler API ...
