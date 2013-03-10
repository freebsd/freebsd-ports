--- src/common/SystemFunctions.cpp.orig	2012-04-17 04:26:14.000000000 +0400
+++ src/common/SystemFunctions.cpp	2012-12-14 23:18:03.318932050 +0400
@@ -63,8 +63,10 @@
 #if defined(__APPLE__) && defined(MAC_OS_X_VERSION_10_6) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_6
 #define HAVE_PTHREAD_NAME
 // glibc 2.12 introduced this
-#elif __GLIBC_PREREQ(2,12)
-#define HAVE_PTHREAD_NAME
+#elif defined(__GLIBC_PREREQ)
+#	if __GLIBC_PREREQ(2,12)
+#		define HAVE_PTHREAD_NAME
+#	endif
 #endif
 #endif
 
