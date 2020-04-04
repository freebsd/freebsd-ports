Fix build with Qt5-5.14

--- src/imagedisplay.h.orig	2020-04-04 12:04:22 UTC
+++ src/imagedisplay.h
@@ -23,6 +23,7 @@
 #ifndef IMAGEDISPLAY_H
 #define IMAGEDISPLAY_H
 
+#include <QElapsedTimer>
 #include <QtWidgets/QWidget>
 #include <QImage>
 #include <QPainter>
@@ -85,7 +86,7 @@ class ImageDisplay : public QWidget {
    QImage*      Image;
    unsigned int OffsetX;
    unsigned int OffsetY;
-   QTime        LastOffsetUpdate;
+   QElapsedTimer LastOffsetUpdate;
    int          MarkX1;
    int          MarkY1;
    int          MarkX2;
