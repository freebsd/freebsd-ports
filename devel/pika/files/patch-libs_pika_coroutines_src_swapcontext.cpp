--- libs/pika/coroutines/src/swapcontext.cpp.orig	2022-07-13 00:26:04 UTC
+++ libs/pika/coroutines/src/swapcontext.cpp
@@ -9,7 +9,7 @@
 
 #if !defined(PIKA_HAVE_GENERIC_CONTEXT_COROUTINES)
 
-#if (defined(__linux) || defined(linux) || defined(__linux__)) &&              \
+#if (defined(__linux) || defined(linux) || defined(__linux__) || defined(__FreeBSD__)) &&              \
     !defined(__bgq__) && !defined(__powerpc__) && !defined(__s390x__)
 
 #if defined(__x86_64__) || defined(__amd64__)
