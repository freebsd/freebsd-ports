--- filters/output/OutputGenerator.cpp.orig	2020-05-21 09:40:03 UTC
+++ filters/output/OutputGenerator.cpp
@@ -25,6 +25,7 @@
 #include <imageproc/ImageCombination.h>
 #include <QDebug>
 #include <QPainter>
+#include <QPainterPath>
 #include <QtCore/QSettings>
 #include <boost/bind.hpp>
 #include "DebugImages.h"
@@ -2666,4 +2667,4 @@ QImage OutputGenerator::posterizeImage(const QImage& i
                  posterizationOptions.isForceBlackAndWhite(), 0, qRound(background_color.lightnessF() * 255))
       .getImage();
 }
-}  // namespace output
\ No newline at end of file
+}  // namespace output
