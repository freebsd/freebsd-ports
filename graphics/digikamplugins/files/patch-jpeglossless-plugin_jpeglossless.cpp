--- ./jpeglossless/plugin_jpeglossless.cpp.orig	Sat Sep  4 11:38:19 2004
+++ ./jpeglossless/plugin_jpeglossless.cpp	Sat Sep  4 11:38:26 2004
@@ -42,7 +42,7 @@
 #include "plugin_jpeglossless.h"
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_jpeglossless,
-                            KGenericFactory<Plugin_JPEGLossless>("digikam"));
+                            KGenericFactory<Plugin_JPEGLossless>("digikam"))
 
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////
