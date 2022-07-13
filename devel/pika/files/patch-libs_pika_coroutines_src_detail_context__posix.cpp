--- libs/pika/coroutines/src/detail/context_posix.cpp.orig	2022-07-13 00:20:17 UTC
+++ libs/pika/coroutines/src/detail/context_posix.cpp
@@ -14,7 +14,7 @@
 
 // left empty on purpose
 
-#elif (defined(__linux) || defined(linux) || defined(__linux__)) &&            \
+#elif (defined(__linux) || defined(linux) || defined(__linux__) || defined(__FreeBSD__)) &&            \
     !defined(__bgq__) && !defined(__powerpc__) && !defined(__s390x__)
 
 // left empty on purpose
