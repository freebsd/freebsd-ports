--- renderer.cpp.orig	Tue Dec  7 03:13:35 1999
+++ renderer.cpp	Wed Jan  4 23:17:40 2006
@@ -1434,7 +1434,7 @@
     
     for(wx=0 ; wx<visiblerect.width(); wx++)
     {
-      switch(*src++)
+      switch((*src++)&0x00FFFFFF)
       {
         case 0x00000000:
           *dest++ = 0;
@@ -1483,8 +1483,8 @@
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
@@ -1562,9 +1562,9 @@
   
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
