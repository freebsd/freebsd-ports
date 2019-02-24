--- flow/libs/system/src/error_code.cpp.orig	2018-09-11 01:21:54 UTC
+++ flow/libs/system/src/error_code.cpp
@@ -43,6 +43,7 @@ using namespace boost::system::errc;
 #endif
 //----------------------------------------------------------------------------//
 
+#if BOOST_VERSION < 106800
 namespace
 {
 #if defined(__PGI)
@@ -434,3 +435,4 @@ namespace boost
 
   } // namespace system
 } // namespace boost
+#endif
