--- src/terrain.c.orig	Tue Jul 16 23:49:58 2002
+++ src/terrain.c	Tue Jul 16 23:50:11 2002
@@ -36,7 +36,7 @@
   
   debugf("Started Loading Map (%s)",course->dir);
   
-  sprintf(temp,"data/%s/%s",course->dir,"map.bmp");
+  sprintf(temp,"%%DATADIR%%/data/%s/%s",course->dir,"map.bmp");
 
   if(!(mapimg = IMG_Load(temp)))
     error("Missing Level Data");
