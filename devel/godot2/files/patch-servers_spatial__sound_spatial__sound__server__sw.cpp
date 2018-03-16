--- servers/spatial_sound/spatial_sound_server_sw.cpp.orig	2018-01-10 16:17:16 UTC
+++ servers/spatial_sound/spatial_sound_server_sw.cpp
@@ -689,7 +689,7 @@ bool SpatialSoundServerSW::internal_buff
 				case 2: {
 
 					float p = sd.panning.x * 0.5 + 0.5;
-					float panf[2] = { (1.0 - p), p };
+					float panf[2] = { (1.0f - p), p };
 					panf[0] *= sd.volume;
 					panf[1] *= sd.volume;
 
@@ -740,7 +740,7 @@ bool SpatialSoundServerSW::internal_buff
 
 					float xp = sd.panning.x * 0.5 + 0.5;
 					float yp = sd.panning.y * 0.5 + 0.5;
-					float panf[4] = { (1.0 - xp) * (1.0 - yp), (xp) * (1.0 - yp), (1.0 - xp) * (yp), (xp) * (yp) };
+					float panf[4] = { (1.0f - xp) * (1.0f - yp), (xp) * (1.0f - yp), (1.0f - xp) * (yp), (xp) * (yp) };
 					panf[0] *= sd.volume;
 					panf[1] *= sd.volume;
 					panf[2] *= sd.volume;
