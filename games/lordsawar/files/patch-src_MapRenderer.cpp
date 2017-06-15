--- src/MapRenderer.cpp.orig	2015-06-10 18:06:19 UTC
+++ src/MapRenderer.cpp
@@ -72,7 +72,7 @@ void MapRenderer::render_tile(Vector<int
     }
   else
     {
-      if (style->getImage() == false)
+      if (!style->getImage())
 	{
 	  printf ("pic for style %d for tile %d at %d,%d is null\n",
 		  style->getType(), mtile->getType(), tile.x, tile.y);
