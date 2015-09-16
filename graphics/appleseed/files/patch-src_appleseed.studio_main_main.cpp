--- src/appleseed.studio/main/main.cpp.orig	2015-06-13 09:38:53 UTC
+++ src/appleseed.studio/main/main.cpp
@@ -174,6 +174,9 @@ namespace
 #ifdef __linux__
         preprocessor.define_symbol("__linux__");
 #endif
+#ifdef __FreeBSD__
+        preprocessor.define_symbol("__FreeBSD__");
+#endif
 
         preprocessor.process(stylesheet.c_str());
 
