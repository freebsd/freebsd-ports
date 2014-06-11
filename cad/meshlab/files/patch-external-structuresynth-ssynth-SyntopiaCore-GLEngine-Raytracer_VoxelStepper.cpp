--- external/structuresynth/ssynth/SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp.orig	2014-05-19 17:17:49.000000000 +0200
+++ external/structuresynth/ssynth/SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp	2014-05-19 17:19:07.000000000 +0200
@@ -122,7 +122,7 @@
 						currentT = p;
 
 						// We do not intersect grid.
-						if (!found) return false;
+						if (!found) return nullptr;
 				}
 
 				stepX = (dir.x() > 0) ? 1 : -1;
