Fix build with Qt5-5.14

--- src/imagedisplay.cc.orig	2020-04-04 12:10:32 UTC
+++ src/imagedisplay.cc
@@ -134,7 +134,7 @@ void ImageDisplay::mousePressEvent(QMouseEvent* mouseE
       MarkX2           = MarkX1;
       MarkY2           = MarkY1;
       Marking          = true;
-      LastOffsetUpdate = QTime::currentTime();
+      LastOffsetUpdate.start();
       update();
    }
 }
@@ -143,7 +143,6 @@ void ImageDisplay::mousePressEvent(QMouseEvent* mouseE
 // ###### Handle mouse release for marking ##################################
 void ImageDisplay::mouseReleaseEvent(QMouseEvent* mouseEvent)
 {
-   LastOffsetUpdate = QTime();
    mouseMoveEvent(mouseEvent);
 
    if((mouseEvent->button() & Qt::LeftButton) && (Marking)) {
@@ -185,7 +184,7 @@ void ImageDisplay::mouseMoveEvent(QMouseEvent* mouseEv
 
       if((movex != 0) || (movey != 0)) {
          offsetUpdate((int)OffsetX + movex, (int)OffsetY + movey);
-         LastOffsetUpdate = QTime::currentTime();
+         LastOffsetUpdate.start();
       }
 
       getMarkPosition(mouseEvent, MarkX2, MarkY2);
