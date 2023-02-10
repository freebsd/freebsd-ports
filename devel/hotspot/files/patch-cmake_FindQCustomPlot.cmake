--- cmake/FindQCustomPlot.cmake.orig	2022-12-21 10:52:32 UTC
+++ cmake/FindQCustomPlot.cmake
@@ -32,7 +32,7 @@
 
 
 find_library(QCustomPlot_LIBRARY
-    NAMES qcustomplot qcustomplot-qt5
+    NAMES QCustomPlot-qt5
 )
 set(QCustomPlot_LIBRARIES "${QCustomPlot_LIBRARY}")
 
