--- Inventor/nodes/SoMarkerSet.i.orig	2018-06-08 08:15:18 UTC
+++ Inventor/nodes/SoMarkerSet.i
@@ -5,7 +5,7 @@
         short WIDTH, HEIGHT;
         size.getValue(WIDTH, HEIGHT);
         short BYTEWIDTH = (WIDTH + 7) / 2;
-        char* coin_marker;
+        const char* coin_marker;
 #ifdef PY_2
         if (PyString_Check(string))
         {
