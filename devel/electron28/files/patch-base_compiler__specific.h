--- base/compiler_specific.h.orig	2023-05-25 00:41:37 UTC
+++ base/compiler_specific.h
@@ -41,9 +41,9 @@
 // Annotate a function indicating it should not be inlined.
 // Use like:
 //   NOINLINE void DoStuff() { ... }
-#if defined(__clang__) && HAS_ATTRIBUTE(noinline)
+#if defined(__clang__) && (__clang_major__ >= 15) && HAS_ATTRIBUTE(noinline)
 #define NOINLINE [[clang::noinline]]
-#elif defined(COMPILER_GCC) && HAS_ATTRIBUTE(noinline)
+#elif (defined(COMPILER_GCC) || defined(__clang__)) && HAS_ATTRIBUTE(noinline)
 #define NOINLINE __attribute__((noinline))
 #elif defined(COMPILER_MSVC)
 #define NOINLINE __declspec(noinline)
@@ -51,9 +51,9 @@
 #define NOINLINE
 #endif
 
-#if defined(__clang__) && defined(NDEBUG) && HAS_ATTRIBUTE(always_inline)
+#if defined(__clang__) && (__clang_major__ >= 15) && defined(NDEBUG) && HAS_ATTRIBUTE(always_inline)
 #define ALWAYS_INLINE [[clang::always_inline]] inline
-#elif defined(COMPILER_GCC) && defined(NDEBUG) && HAS_ATTRIBUTE(always_inline)
+#elif (defined(COMPILER_GCC) || defined(__clang__)) && defined(NDEBUG) && HAS_ATTRIBUTE(always_inline)
 #define ALWAYS_INLINE inline __attribute__((__always_inline__))
 #elif defined(COMPILER_MSVC) && defined(NDEBUG)
 #define ALWAYS_INLINE __forceinline
@@ -69,7 +69,7 @@
 // prevent code folding, see NO_CODE_FOLDING() in base/debug/alias.h.
 // Use like:
 //   NOT_TAIL_CALLED void FooBar();
-#if defined(__clang__) && HAS_ATTRIBUTE(not_tail_called)
+#if defined(__clang__) && (__clang_major__ >= 15) && HAS_ATTRIBUTE(not_tail_called)
 #define NOT_TAIL_CALLED [[clang::not_tail_called]]
 #else
 #define NOT_TAIL_CALLED
