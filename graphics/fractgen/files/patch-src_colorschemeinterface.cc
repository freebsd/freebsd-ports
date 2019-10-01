--- src/colorschemeinterface.cc.orig	2019-09-01 12:18:45 UTC
+++ src/colorschemeinterface.cc
@@ -24,6 +24,7 @@
 
 #include <string.h>
 
+#include <algorithm>
 
 QList<ColorSchemeInterface*>* ColorSchemeInterface::ColorSchemeList = nullptr;
 bool                          ColorSchemeInterface::Updated         = false;
@@ -69,7 +70,7 @@ static bool lessThan(const ColorSchemeInterface* c1,
 ColorSchemeInterface* ColorSchemeInterface::getColorScheme(const unsigned int index)
 {
    if(Updated) {
-      qSort(ColorSchemeList->begin(), ColorSchemeList->end(), lessThan);
+      std::sort(ColorSchemeList->begin(), ColorSchemeList->end(), lessThan);
       Updated = false;
    }
    return(ColorSchemeList->value(index, nullptr));
