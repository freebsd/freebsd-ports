--- plugins/view/HistogramView/HistogramStatistics.cpp.orig	2015-04-18 20:15:49 UTC
+++ plugins/view/HistogramView/HistogramStatistics.cpp
@@ -30,7 +30,7 @@
 #include "HistoStatsConfigWidget.h"
 #include "HistogramView.h"
 
-#if defined(_MSC_VER) || (defined(__clang_major__) && __clang_major__ > 4)
+#if defined(_MSC_VER) || (defined(__clang_major__) && __clang_major__ > 4) || defined(__FreeBSD__)
 
 #include <functional>
 
