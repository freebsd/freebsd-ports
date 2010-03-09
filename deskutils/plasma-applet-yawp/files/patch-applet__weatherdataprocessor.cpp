--- ./applet/weatherdataprocessor.cpp.orig	2009-12-06 15:08:29.000000000 -0500
+++ ./applet/weatherdataprocessor.cpp	2010-02-05 03:23:32.000000000 -0500
@@ -30,7 +30,7 @@
 
 //--- KDE4 ---
 
-#include <values.h>
+#include <float.h>
 #if KDE_IS_VERSION(4,3,70)
 	#include <KUnitConversion/Value>
 #endif
