--- filters/page_layout/ImageView.cpp.orig	2020-05-21 09:34:10 UTC
+++ filters/page_layout/ImageView.cpp
@@ -27,6 +27,7 @@
 #include <imageproc/Transform.h>
 #include <QMouseEvent>
 #include <QPainter>
+#include <QPainterPath>
 #include <boost/bind.hpp>
 #include <boost/lambda/lambda.hpp>
 #include "ImagePresentation.h"
@@ -1160,4 +1161,4 @@ void ImageView::enableMiddleRectInteraction(const bool
 bool ImageView::isShowingMiddleRectEnabled() const {
   return (!m_nullContentRect && m_settings->isShowingMiddleRectEnabled()) || m_alignment.isNull();
 }
-}  // namespace page_layout
\ No newline at end of file
+}  // namespace page_layout
