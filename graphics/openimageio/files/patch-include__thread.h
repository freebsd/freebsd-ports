--- ./include/thread.h.orig       2012-11-10 05:51:18.000000000 +1030
+++ ./include/thread.h     2012-11-11 17:25:34.547296939 +1030
@@ -70,9 +70,14 @@
 #pragma GCC diagnostic error "-Wunused-variable"
 #endif
 
+#if defined(__GNUC__) && (defined(_GLIBCXX_ATOMIC_BUILTINS) || (__GNUC__ * 100 + __GNUC_MINOR__ >= 401))
+#define USE_GCC_ATOMICS 1
+#undef USE_TBB
+#else
 #ifndef USE_TBB
 #  define USE_TBB 0
 #endif
+#endif
 
 // Include files we need for atomic counters.
 // Some day, we hope this is all replaced by use of std::atomic<>.
@@ -97,12 +102,6 @@
 #  include <libkern/OSAtomic.h>
 #endif
 
-#if defined(__GNUC__) && (defined(_GLIBCXX_ATOMIC_BUILTINS) || (__GNUC__ * 100 + __GNUC_MINOR__ >= 401))
-#if !defined(__FreeBSD__) || defined(__x86_64__)
-#define USE_GCC_ATOMICS
-#endif
-#endif
-
 OIIO_NAMESPACE_ENTER
 {
 
