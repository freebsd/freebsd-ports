--- plugins/view/HistogramView/HistogramStatistics.cpp.orig	2014-04-18 12:05:56.000000000 +0200
+++ plugins/view/HistogramView/HistogramStatistics.cpp	2014-04-18 12:07:56.000000000 +0200
@@ -30,7 +30,7 @@
 #include "HistoStatsConfigWidget.h"
 #include "HistogramView.h"
 
-#if defined(_MSC_VER) || (defined(__clang_major__) && __clang_major__ > 4)
+#if defined(_MSC_VER) || (defined(__clang_major__) && __clang_major__ > 4) || defined(__FreeBSD__)
 
 #include <functional>
 
