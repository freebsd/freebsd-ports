--- boost/config/platform/bsd.hpp.orig	Fri Feb 27 14:13:00 2004
+++ boost/config/platform/bsd.hpp	Wed Dec 15 16:01:21 2004
@@ -39,9 +39,20 @@
 #endif
 
 //
-// No wide character support in the BSD header files:
+// Enable wide character support on FreeBSD 5 and above
 //
-#define BOOST_NO_CWCHAR
+#if defined(__FreeBSD__) && (__FreeBSD__ >= 5)
+#  undef BOOST_NO_CWCHAR
+#  undef BOOST_NO_SWPRINTF
+#  undef BOOST_NO_CWCTYPE
+#  undef BOOST_DEDUCED_TYPENAME
+#else
+#  define BOOST_NO_CWCHAR
+#  define BOOST_NO_SWPRINTF
+#  define BOOST_NO_CWCTYPE
+#endif
+ 
+#define BOOST_NO_INCLASS_MEMBER_INITIALIZATION
 
 //
 // The BSD <ctype.h> has macros only, no functions:
