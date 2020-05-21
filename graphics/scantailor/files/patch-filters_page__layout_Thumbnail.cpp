--- filters/page_layout/Thumbnail.cpp.orig	2020-05-21 09:40:03 UTC
+++ filters/page_layout/Thumbnail.cpp
@@ -18,6 +18,7 @@
 
 #include "Thumbnail.h"
 #include <QPainter>
+#include <QPainterPath>
 #include <utility>
 #include "Utils.h"
 #include "imageproc/PolygonUtils.h"
@@ -111,4 +112,4 @@ void Thumbnail::paintOverImage(QPainter& painter,
     paintDeviant(painter);
   }
 }  // Thumbnail::paintOverImage
-}  // namespace page_layout
\ No newline at end of file
+}  // namespace page_layout
