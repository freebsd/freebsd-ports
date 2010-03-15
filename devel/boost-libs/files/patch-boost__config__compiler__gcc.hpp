--- boost/config/compiler/gcc.hpp.orig	2010-02-24 00:41:39.000000000 -0300
+++ boost/config/compiler/gcc.hpp	2010-02-24 00:44:56.000000000 -0300
@@ -104,6 +104,13 @@
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
