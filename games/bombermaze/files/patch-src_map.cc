
$FreeBSD$

--- src/map.cc.orig	Sun Feb 25 08:50:07 2001
+++ src/map.cc	Sun Aug 22 21:25:12 2004
@@ -1587,7 +1587,7 @@
   width = w;
   height = h;
 
-  map = new (char *)[width];
+  map = new char * [width];
 
   unsigned i;
   for (i = 0; i < width; i++)
@@ -1728,7 +1728,7 @@
 
 void GameMap::allocate_map(MapSquare ***m)
 {
-  *m = new (MapSquare *)[width];
+  *m = new MapSquare * [width];
   int i;
   for (i = 0; i < width; i++)
   {
