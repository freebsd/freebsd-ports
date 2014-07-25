--- DungeonMaker.h.orig	2014-07-24 11:55:26.000000000 -0400
+++ DungeonMaker.h	2014-07-24 11:55:51.000000000 -0400
@@ -22,6 +22,7 @@
 #include <list>
 #include <string>
 #include <assert.h>
+#include <stdlib.h>
 
 ///* ATTENTION: In this version, the method DungeonMaker:: PutPlonkOnMap() puts MOBs and treasure on the map literally, by changing the SquareData of the Map square where the stuff goes. This is just for demonstration purposes to make it easier to show stuff without having an engine for rendering objects. If you use the DungeonMaker in your own program, you must refrain from calling this function, and instead write your own function that puts stuff on the map as objects and leaves the MapData as it is.
 
