--- src/Effects/Distorsion.cpp.orig	2022-01-22 01:46:21 UTC
+++ src/Effects/Distorsion.cpp
@@ -75,7 +75,7 @@ rtosc::Ports Distorsion::ports = {
 
             for(int i=0; i<128; ++i)
                 buffer[i] = 2*(i/128.0)-1;
-            memcpy(orig, buffer, sizeof(float_t)*128);
+            memcpy(orig, buffer, sizeof(buffer));
 
             waveShapeSmps(sizeof(buffer)/sizeof(buffer[0]), buffer,
                     dd.Ptype + 1, dd.Pdrive, dd.Poffset, dd.Pfuncpar);
