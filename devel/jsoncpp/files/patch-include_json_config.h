--- include/json/config.h.orig	2016-05-09 23:16:22 UTC
+++ include/json/config.h
@@ -77,7 +77,7 @@
 
 #endif // defined(_MSC_VER)
 
-#if defined(_MSC_VER) && _MSC_VER <= 1600 // MSVC <= 2010
+#if defined(__FreeBSD__) || (defined(_MSC_VER) && _MSC_VER <= 1600) // MSVC <= 2010
 # define JSONCPP_OVERRIDE
 #else
 # define JSONCPP_OVERRIDE override
