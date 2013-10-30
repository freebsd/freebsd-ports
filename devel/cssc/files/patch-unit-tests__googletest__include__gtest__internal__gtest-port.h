--- ./unit-tests/googletest/include/gtest/internal/gtest-port.h.orig	2010-05-15 18:30:14.000000000 -0400
+++ ./unit-tests/googletest/include/gtest/internal/gtest-port.h	2013-10-29 12:25:07.000000000 -0400
@@ -80,6 +80,7 @@
 // the given platform; otherwise undefined):
 //   GTEST_OS_AIX      - IBM AIX
 //   GTEST_OS_CYGWIN   - Cygwin
+//   GTEST_OS_FREEBSD  - FreeBSD
 //   GTEST_OS_LINUX    - Linux
 //   GTEST_OS_MAC      - Mac OS X
 //   GTEST_OS_SOLARIS  - Sun Solaris
@@ -219,10 +220,13 @@
 #define GTEST_OS_SOLARIS 1
 #elif defined(_AIX)
 #define GTEST_OS_AIX 1
+#elif defined(__FreeBSD__)
+#define GTEST_OS_FREEBSD 1
+#define GTEST_USE_OWN_TR1_TUPLE 1
 #endif  // __CYGWIN__
 
 #if GTEST_OS_CYGWIN || GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_SYMBIAN || \
-    GTEST_OS_SOLARIS || GTEST_OS_AIX
+    GTEST_OS_SOLARIS || GTEST_OS_AIX || GTEST_OS_FREEBSD
 
 // On some platforms, <regex.h> needs someone to define size_t, and
 // won't compile otherwise.  We can #include it here as we already
@@ -254,7 +258,8 @@
 #define GTEST_USES_SIMPLE_RE 1
 
 #endif  // GTEST_OS_CYGWIN || GTEST_OS_LINUX || GTEST_OS_MAC ||
-        // GTEST_OS_SYMBIAN || GTEST_OS_SOLARIS || GTEST_OS_AIX
+        // GTEST_OS_SYMBIAN || GTEST_OS_SOLARIS || GTEST_OS_AIX ||
+        // GTEST_OS_FREEBSD
 
 #ifndef GTEST_HAS_EXCEPTIONS
 // The user didn't tell us whether exceptions are enabled, so we need
@@ -376,7 +381,7 @@
 //
 // To disable threading support in Google Test, add -DGTEST_HAS_PTHREAD=0
 // to your compiler flags.
-#define GTEST_HAS_PTHREAD (GTEST_OS_LINUX || GTEST_OS_MAC)
+#define GTEST_HAS_PTHREAD (GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_FREEBSD)
 #endif  // GTEST_HAS_PTHREAD
 
 // Determines whether Google Test can use tr1/tuple.  You can define
@@ -483,6 +488,7 @@
 // abort() in a VC 7.1 application compiled as GUI in debug config
 // pops up a dialog window that cannot be suppressed programmatically.
 #if (GTEST_OS_LINUX || GTEST_OS_MAC || GTEST_OS_CYGWIN || GTEST_OS_SOLARIS || \
+     GTEST_OS_FREEBSD || \
      (GTEST_OS_WINDOWS_DESKTOP && _MSC_VER >= 1400) || \
      GTEST_OS_WINDOWS_MINGW || GTEST_OS_AIX)
 #define GTEST_HAS_DEATH_TEST 1
