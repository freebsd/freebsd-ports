- workaround for https://github.com/gperftools/gperftools/issues/1271

--- src/stacktrace.cc.orig	2021-04-23 06:18:43 UTC
+++ src/stacktrace.cc
@@ -219,7 +219,7 @@ static GetStackImplementation *all_impls[] = {
 
 // ppc and i386 implementations prefer arch-specific asm implementations.
 // arm's asm implementation is broken
-#if defined(__i386__) || defined(__ppc__) || defined(__PPC__)
+#if defined(__i386__) || defined(__x86_64__) || defined(__ppc__) || defined(__PPC__)
 #if !defined(NO_FRAME_POINTER)
 #define TCMALLOC_DONT_PREFER_LIBUNWIND
 #endif
