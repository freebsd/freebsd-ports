--- libs/pika/coroutines/src/swapcontext.cpp.orig	2023-03-08 10:50:55 UTC
+++ libs/pika/coroutines/src/swapcontext.cpp
@@ -9,7 +9,7 @@
 
 #if !defined(PIKA_HAVE_GENERIC_CONTEXT_COROUTINES)
 
-# if (defined(__linux) || defined(linux) || defined(__linux__)) && !defined(__bgq__) &&            \
+# if (defined(__linux) || defined(linux) || defined(__linux__) || defined(__FreeBSD__)) && !defined(__bgq__) &&            \
      !defined(__powerpc__) && !defined(__s390x__) && !defined(__arm__) && !defined(__arm64__) &&   \
      !defined(__aarch64__)
 
