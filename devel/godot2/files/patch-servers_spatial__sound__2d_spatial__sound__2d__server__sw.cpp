--- servers/spatial_sound_2d/spatial_sound_2d_server_sw.cpp.orig	2018-01-10 18:13:07 UTC
+++ servers/spatial_sound_2d/spatial_sound_2d_server_sw.cpp
@@ -675,7 +675,7 @@ bool SpatialSound2DServerSW::internal_bu
 				case 2: {
 
 					float p = sd.panning.x * 0.5 + 0.5;
-					float panf[2] = { (1.0 - p), p };
+					float panf[2] = { (1.0f - p), p };
 					panf[0] *= sd.volume;
 					panf[1] *= sd.volume;
 
@@ -726,7 +726,7 @@ bool SpatialSound2DServerSW::internal_bu
 
 					float xp = sd.panning.x * 0.5 + 0.5;
 					float yp = sd.panning.y * 0.5 + 0.5;
-					float panf[4] = { (1.0 - xp) * (1.0 - yp), (xp) * (1.0 - yp), (1.0 - xp) * (yp), (xp) * (yp) };
+					float panf[4] = { (1.0f - xp) * (1.0f - yp), (xp) * (1.0f - yp), (1.0f - xp) * (yp), (xp) * (yp) };
 					panf[0] *= sd.volume;
 					panf[1] *= sd.volume;
 					panf[2] *= sd.volume;
