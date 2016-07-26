--- renderer.cpp.orig	1999-12-06 16:13:35 UTC
+++ renderer.cpp
@@ -123,7 +123,7 @@ Renderer::Renderer(const QSize &size, co
   this->ambientGreen = 0.15;
   this->ambientBlue = 0.15;
   this->markerpixmap = new QPixmap((const char **)marker_xpm);
-  ASSERT(markerpixmap != NULL);
+  Q_ASSERT(markerpixmap != NULL);
   this->show_label = TRUE;
   this->gridtype = NO_GRID;
   this->d_gridline = 15.0*PI/180.;
@@ -448,7 +448,7 @@ double Renderer::getZoom()
 
 void Renderer::setMarkerList(MarkerList *l)
 {
-  ASSERT(l != NULL);
+  Q_ASSERT(l != NULL);
   markerlist = l;
 }
 
@@ -1136,7 +1136,7 @@ void Renderer::drawMarkers()
   Location **visible_locations;
 
   visible_locations = new Location*[markerlist->count()];
-  ASSERT(visible_locations != NULL);
+  Q_ASSERT(visible_locations != NULL);
 
   // Matrix M of renderFrame, but transposed
   m11 = cos(rot)*cos(view_long)-sin(view_lat)*sin(view_long)*sin(rot);
@@ -1151,8 +1151,9 @@ void Renderer::drawMarkers()
 
   visible_angle = radius/center_dist;
   
-  for(i=0, l = markerlist->first(); l != NULL; l = markerlist->next())
+  for(i=0, num=0; i < markerlist->size(); ++i)
   {
+    l = markerlist->atindex(i);
     lon = l->getLongitude()*PI/180.;
     lat = l->getLatitude()*PI/180.;
 
@@ -1185,12 +1186,9 @@ void Renderer::drawMarkers()
     l->x = screen_x + shift_x;
     l->y = screen_y + shift_y;
 
-    visible_locations[i] = l;
-    i++;
+    visible_locations[num++] = l;
   }
 
-  num = i;
-
   // sort the markers according to depth
   qsort(visible_locations, num, sizeof(Location *),
         Renderer::compareLocations);
@@ -1208,8 +1206,8 @@ int Renderer::compareLocations(const voi
 {
   double c1, c2;
   
-  c1 = (*((Location **)l1))->cos_angle;
-  c2 = (*((Location **)l2))->cos_angle;
+  c1 = ((Location *)l1)->cos_angle;
+  c2 = ((Location *)l2)->cos_angle;
   
   if(c1 > c2)
     return 1;
@@ -1364,7 +1362,7 @@ QImage *Renderer::getImage()
   QImage *clonedImage = NULL;
 
   clonedImage = new QImage(*renderedImage);
-  ASSERT(clonedImage != NULL);
+  Q_ASSERT(clonedImage != NULL);
   return clonedImage;
 }
 
@@ -1391,7 +1389,7 @@ void Renderer::paintMarker(int x, int y,
 #if QT_VERSION >= 200  
   p.setPen(Qt::black);
 #else
-  p.setPen(black);
+  p.setPen(Qt::black);
 #endif
   wx = -br.x()+markerpixmap->width()+2;
   wy = -br.y();
@@ -1434,7 +1432,7 @@ void Renderer::paintMarker(int x, int y,
     
     for(wx=0 ; wx<visiblerect.width(); wx++)
     {
-      switch(*src++)
+      switch((*src++)&0x00FFFFFF)
       {
         case 0x00000000:
           *dest++ = 0;
@@ -1483,8 +1481,8 @@ void Renderer::drawLabel()
   labelstring.sprintf("%s, %s %d. %d, %d:%02d %s\n"
                       "View pos %2.2f° %c %2.2f° %c\n"
                       "Sun pos %2.2f° %c %2.2f° %c",
-                      dt.date().dayName(dt.date().dayOfWeek()),
-                      dt.date().monthName(dt.date().month()),
+                      dt.date().dayName(dt.date().dayOfWeek()).latin1(),
+                      dt.date().monthName(dt.date().month()).latin1(),
                       dt.date().day(), dt.date().year(),
                       dt.time().hour(), dt.time().minute(),
                       tzname[tm->tm_isdst],
@@ -1499,7 +1497,7 @@ void Renderer::drawLabel()
   QRect br = fm.boundingRect(0, 0, 0, 0, Qt::AlignLeft|Qt::AlignTop,
                              labelstring);
 #else
-  QRect br = fm.boundingRect(0, 0, 0, 0, AlignLeft|AlignTop, labelstring);
+  QRect br = fm.boundingRect(0, 0, 0, 0, Qt::AlignLeft|Qt::AlignTop, labelstring);
 #endif
   QPixmap pm(br.width()+10, br.height()+10);
   
@@ -1512,8 +1510,8 @@ void Renderer::drawLabel()
   p.drawText(5, 5, br.width(), br.height(), Qt::AlignLeft|Qt::AlignTop,
              labelstring);
 #else
-  p.setPen(white);
-  p.drawText(5, 5, br.width(), br.height(), AlignLeft|AlignTop, labelstring);
+  p.setPen(Qt::white);
+  p.drawText(5, 5, br.width(), br.height(), Qt::AlignLeft|Qt::AlignTop, labelstring);
 #endif
   p.end();
   
@@ -1562,9 +1560,9 @@ void Renderer::drawStars()
   
   for(int i=0; i<numstars; i++)
   {
-    x = rand() % renderedImage->width();
-    y = rand() % renderedImage->height();
-    brightness = 150+ (rand() % 106);
+    x = random() % renderedImage->width();
+    y = random() % renderedImage->height();
+    brightness = 150+ (random() % 106);
     p = (unsigned int *)renderedImage->scanLine(y);
     p += x;
     *p = qRgb(brightness, brightness, brightness);
