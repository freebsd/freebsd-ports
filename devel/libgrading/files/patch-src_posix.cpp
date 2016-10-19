--- src/posix.cpp.orig	2016-09-19 18:47:05 UTC
+++ src/posix.cpp
@@ -186,6 +186,11 @@ TestResult grading::ForkTest(TestClosure
 
 
 #ifdef __FreeBSD__
+#include <sys/param.h>
+#endif
+
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1001511
+
 #include <sys/capsicum.h>
 
 #include <err.h>
