--- boost/config/compiler/gcc.hpp.orig	2010-10-01 09:19:44.000000000 +0000
+++ boost/config/compiler/gcc.hpp	2010-11-20 10:59:22.000000000 +0000
@@ -146,6 +149,13 @@
 #  endif
 #endif
 
+//
+// gcc previous to 4.3.x does not implement inclass member initialization
+//
+#if (__GNUC__ < 4 || (__GNUC__ == 4 && __GNUC_MINOR__ <= 2))
+#  define BOOST_NO_INCLASS_MEMBER_INITIALIZATION
+#endif
+
 // C++0x features not implemented in any GCC version
 //
 #define BOOST_NO_CONSTEXPR
