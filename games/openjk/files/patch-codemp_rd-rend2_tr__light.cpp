--- codemp/rd-rend2/tr_light.cpp.orig	2026-07-11 05:28:28 UTC
+++ codemp/rd-rend2/tr_light.cpp
@@ -181,10 +181,6 @@ static void R_SetupEntityLightingGrid( trRefEntity_t *
 		int		lat, lng;
 		vec3_t	normal;
 
-		#if idppc
-		float d0, d1, d2, d3, d4, d5;
-		#endif
-
 		factor = 1.0;
 		gridPos = startGridPos;
 
@@ -209,18 +205,6 @@ static void R_SetupEntityLightingGrid( trRefEntity_t *
 		}
 
 		totalFactor += factor;
-		#if idppc
-		d0 = data[0]; d1 = data[1]; d2 = data[2];
-		d3 = data[3]; d4 = data[4]; d5 = data[5];
-
-		ent->ambientLight[0] += factor * d0;
-		ent->ambientLight[1] += factor * d1;
-		ent->ambientLight[2] += factor * d2;
-
-		ent->directedLight[0] += factor * d3;
-		ent->directedLight[1] += factor * d4;
-		ent->directedLight[2] += factor * d5;
-		#else
 		if (world->hdrLightGrid)
 		{
 			float *hdrData = world->hdrLightGrid + (gridPos * 6);
@@ -254,7 +238,6 @@ static void R_SetupEntityLightingGrid( trRefEntity_t *
 				}
 			}
 		}
-		#endif
 		lat = data->latLong[1];
 		lng = data->latLong[0];
 		lat *= (FUNCTABLE_SIZE/256);
