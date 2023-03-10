--- libs/pika/coroutines/src/detail/context_posix.cpp.orig	2023-03-08 10:50:55 UTC
+++ libs/pika/coroutines/src/detail/context_posix.cpp
@@ -14,7 +14,7 @@
 
 // left empty on purpose
 
-#elif (defined(__linux) || defined(linux) || defined(__linux__)) && !defined(__bgq__) &&           \
+#elif (defined(__linux) || defined(linux) || defined(__linux__) || defined(__FreeBSD__)) && !defined(__bgq__) &&           \
     !defined(__powerpc__) && !defined(__s390x__) && !defined(__arm__) && !defined(__arm64__) &&    \
     !defined(__aarch64__)
 
