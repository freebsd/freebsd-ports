--- boost/config/platform/bsd.hpp.orig	Sat Feb  5 12:53:03 2005
+++ boost/config/platform/bsd.hpp	Sat Feb  5 12:53:46 2005
@@ -41,8 +41,9 @@
 //
 // No wide character support in the BSD header files:
 //
-#define BOOST_NO_CWCHAR
-
+#if !(defined(__FreeBSD__) && (__FreeBSD__ >= 5))
+#  define BOOST_NO_CWCHAR
+#endif
 //
 // The BSD <ctype.h> has macros only, no functions:
 //
