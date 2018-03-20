Fix build with modern Clang

../hyperlinkarea.cpp:35:18: error: zero as null pointer constant [-Werror,-Wzero-as-null-pointer-constant]
  if ( pixmap == 0 )
                 ^
                 nullptr

--- hyperlinkarea.cpp.orig	2018-03-11 12:58:40 UTC
+++ hyperlinkarea.cpp
@@ -32,7 +32,7 @@ HyperlinkArea::HyperlinkArea(QLabel* ima
     throw WrongLinkType();
   QRect mySize;
   const QPixmap* pixmap = imageLabel->pixmap();
-  if ( pixmap == 0 )
+  if ( pixmap == nullptr )
     throw /** FIXME Exception **/ std::runtime_error("Tried to construct a HyperlinkArea from an image label without a pixmap");
   
   QRectF sizeWithinImageLabel = link.linkArea();
