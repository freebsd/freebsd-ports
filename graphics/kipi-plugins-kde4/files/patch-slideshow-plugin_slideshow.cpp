--- ./slideshow/plugin_slideshow.cpp.orig	Sat Sep  4 11:46:53 2004
+++ ./slideshow/plugin_slideshow.cpp	Sat Sep  4 11:47:01 2004
@@ -36,7 +36,7 @@
 #include "slideshowconfig.h"
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_slideshow,
-                            KGenericFactory<Plugin_SlideShow>("digikam"));
+                            KGenericFactory<Plugin_SlideShow>("digikam"))
 
 Plugin_SlideShow::Plugin_SlideShow(QObject *parent,
                                    const char*,
