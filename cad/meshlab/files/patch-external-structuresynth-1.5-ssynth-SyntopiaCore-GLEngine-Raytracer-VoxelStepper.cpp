--- external/structuresynth-1.5/ssynth/SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp.orig	2014-02-07 10:38:23.000000000 +0100
+++ external/structuresynth-1.5/ssynth/SyntopiaCore/GLEngine/Raytracer/VoxelStepper.cpp	2015-01-25 18:58:54.000000000 +0100
@@ -122,7 +122,7 @@
 						currentT = p;
 
 						// We do not intersect grid.
-						if (!found) return false;
+						if (!found) return nullptr;
 				}
 
 				stepX = (dir.x() > 0) ? 1 : -1;
