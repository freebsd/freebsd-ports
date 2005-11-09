--- libs/serialization/src/stl_port.cpp.orig	Sun Aug 21 14:03:45 2005
+++ libs/serialization/src/stl_port.cpp	Sun Aug 21 14:04:37 2005
@@ -32,11 +32,6 @@
     const locale& __loc, boost::archive::codecvt_null<char> * __f
 );
 
-template
-locale::locale(
-    const locale& __loc, boost::archive::codecvt_null<wchar_t> * __f
-);
-
 } // namespace std
 
 #endif
