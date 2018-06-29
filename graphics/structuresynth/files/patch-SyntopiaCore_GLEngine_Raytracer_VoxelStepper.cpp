--- SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp.orig	2010-09-08 17:25:30 UTC
+++ SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp
@@ -122,7 +122,7 @@ namespace SyntopiaCore {
 						currentT = p;
 
 						// We do not intersect grid.
-						if (!found) return false;
+						if (!found) return NULL;
 				}
 
 				stepX = (dir.x() > 0) ? 1 : -1;
