--- earthapp.cpp.orig	1999-12-06 08:14:10.000000000 -0800
+++ earthapp.cpp	2011-01-19 09:28:15.000000000 -0800
@@ -69,6 +69,12 @@
 #include "config.h"
 #include "earthapp.h"
 #include "moonpos.h"
+//Added by qt3to4:
+#include <QPixmap>
+#include <QPalette>
+#include <QX11Info>
+
+#include <X11/Xlib.h>
 
 /* ------------------------------------------------------------------------*/
 
@@ -334,7 +340,7 @@
   if(use_kde)
   {
     dwidget = new DesktopWidget();
-    ASSERT(dwidget != NULL);
+    Q_ASSERT(dwidget != NULL);
     dwidget->update();
   }
 }
@@ -343,9 +349,9 @@
 
 EarthApplication::~EarthApplication(void)
 {
-  ASSERT(r != NULL);
+  Q_ASSERT(r != NULL);
   delete r;
-  ASSERT(timer != NULL);
+  Q_ASSERT(timer != NULL);
   timer->stop();
   delete timer;
 
@@ -937,8 +943,8 @@
 
 void EarthApplication::randomPosition()
 {
-  view_lat = ((rand()%30001)/30000.)*180. - 90.;
-  view_long = ((rand()%30001)/30000.)*360. - 180.;
+  view_lat = ((random()%30001)/30000.)*180. - 90.;
+  view_long = ((random()%30001)/30000.)*360. - 180.;
 }
 
 /* ------------------------------------------------------------------------*/
@@ -1233,7 +1239,7 @@
   r->setRotation(rotation);
 
   timer = new QTimer(this);
-  ASSERT(timer != NULL);
+  Q_ASSERT(timer != NULL);
   
   connect(timer, SIGNAL(timeout()), this, SLOT(recalc()));
   QTimer::singleShot(1, this, SLOT(recalc())); // this will start rendering
@@ -1307,7 +1313,19 @@
   {
     QPixmap pm;
     pm.convertFromImage(*(r->getImage()));
-    desktop()->setBackgroundPixmap(pm);
+
+
+    QPalette palette;
+    palette.setBrush(desktop()->backgroundRole(), QBrush(pm));
+    desktop()->setPalette(palette);
+
+    //
+    // With Qt4, this step seems to be necessary to make the
+    // changes appear immediately. Is there a way to do it via
+    // Qt4 methods?
+    //
+    XClearWindow(QX11Info::display(), QX11Info::appRootWindow());
+
     if(once)
     {
       processEvents();
