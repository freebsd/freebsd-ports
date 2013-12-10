--- src/Platform.hpp.orig	2011-05-02 11:39:00.000000000 +0400
+++ src/Platform.hpp	2013-12-10 06:09:21.766657123 +0400
@@ -127,7 +127,9 @@
 #include <string>
 
 using namespace std;
+#ifndef _LIBCPP_VERSION
 using namespace std::tr1;
+#endif
 
 void RecreateScreens();
 string LocateResource(const string& file);
