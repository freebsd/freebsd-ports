--- src/colorschemeinterface.cc.orig	2019-09-01 12:18:45 UTC
+++ src/colorschemeinterface.cc
@@ -24,6 +24,7 @@
 
 #include <string.h>
 
+#include <algorithm>
 
 QList<ColorSchemeInterface*>* ColorSchemeInterface::ColorSchemeList = nullptr;
 bool                          ColorSchemeInterface::Updated         = false;
