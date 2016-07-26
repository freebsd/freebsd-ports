--- desktopwidget.cpp.orig	1998-12-09 18:15:52 UTC
+++ desktopwidget.cpp
@@ -18,10 +18,14 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include "desktopwidget.h"
+//Added by qt3to4:
+#include <QPaintEvent>
+#include <QPixmap>
 
 DesktopWidget::DesktopWidget(QWidget *parent, const char *name)
-    : QWidget( parent, name, WType_Desktop | WPaintDesktop)
+    : QWidget( parent, name, Qt::WType_Desktop | Qt::WPaintDesktop)
 {
   haveImage = FALSE;
   currentImage = new QPixmap(width(), height());
@@ -43,6 +47,7 @@ void DesktopWidget::paintEvent(QPaintEve
 {
   QPainter p(this);
   
+  printf("DesktopWidget::paintEvent\n");
   if(!haveImage)
   {
     p.setFont(QFont("helvetica", 35));
@@ -62,7 +67,8 @@ void DesktopWidget::paintEvent(QPaintEve
 
 void DesktopWidget::updateDisplay(QImage *image)
 {
-  ASSERT(image != NULL);
+  fprintf(stderr, "updateDisplay called\n");
+  Q_ASSERT(image != NULL);
   currentImage->convertFromImage(*image);
   haveImage = TRUE;
   setBackgroundPixmap(*currentImage);
