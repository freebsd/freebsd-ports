--- src/autoroute.c.orig	Mon Oct  9 15:57:46 2006
+++ src/autoroute.c	Mon Oct  9 15:58:14 2006
@@ -647,8 +647,9 @@
 {
   int is_not_rectangle = 1;
   int layergroup = GetLayerGroupNumberByNumber (layer);
+  routebox_t *rb;
   assert (0 <= layergroup && layergroup < max_layer);
-  routebox_t *rb = AddIrregularObstacle (layergroupboxes,
+  rb = AddIrregularObstacle (layergroupboxes,
 					 polygon->BoundingBox.X1,
 					 polygon->BoundingBox.Y1,
 					 polygon->BoundingBox.X2,
