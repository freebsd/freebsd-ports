--- ./liboslexec/dictionary.cpp.orig	2013-07-12 08:31:18.000000000 +0930
+++ ./liboslexec/dictionary.cpp	2013-11-03 18:07:25.650119434 +1030
@@ -50,7 +50,7 @@
 namespace pvt {   // OSL::pvt
 
 
-#ifndef USE_EXTERNAL_PUGIXML
+#ifdef USING_OIIO_PUGI
 namespace pugi = OIIO::pugi;
 #endif
 
