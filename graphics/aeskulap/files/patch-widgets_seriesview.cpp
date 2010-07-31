--- widgets/seriesview.cpp.orig	2010-07-27 15:03:43.000000000 +0000
+++ widgets/seriesview.cpp	2010-07-27 15:03:57.000000000 +0000
@@ -36,6 +36,8 @@
 
 #include <iostream>
 
+#include <libintl.h>
+
 SeriesView::SeriesView(const Glib::RefPtr<ImagePool::Series>& series) : 
 Aeskulap::Tiler<Aeskulap::Display>(1, 1),
 m_selected(false),
