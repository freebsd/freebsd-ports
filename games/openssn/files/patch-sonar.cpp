--- ./sonar.cpp.orig	2011-05-29 21:42:19.000000000 -0300
+++ ./sonar.cpp	2011-05-29 21:42:56.000000000 -0300
@@ -366,7 +366,7 @@
 		int relative_bearing = bearing_to_target - recipbearing;
 		if(relative_bearing > 150 && relative_bearing < 210) sensordeaf = true;
 		if (!sensordeaf){	
-			noisecolor=SDL_MapRGB(sonarscreen->format, 0,(int) abs((flowandambientnoise - RandInt(40))) , 0);
+			noisecolor=SDL_MapRGB(sonarscreen->format, 0,(int) fabs((flowandambientnoise - RandInt(40))) , 0);
 			DPixel(sonarscreen, nbp, 0, noisecolor);
 		}
 		else{
@@ -407,7 +407,7 @@
 			int relative_bearing = bearing_to_target - recipbearing;
 			if(relative_bearing > 150 && relative_bearing < 210) sensordeaf = true;		
 			if (!sensordeaf){	
-				noisecolor=SDL_MapRGB(sonarscreen->format, 0,(int) abs((flowandambientnoise - RandInt(40))) , 0);
+				noisecolor=SDL_MapRGB(sonarscreen->format, 0,(int) fabs((flowandambientnoise - RandInt(40))) , 0);
 				DPixel(sonarscreen, nbp, 70, noisecolor);
 			}
 			else{
@@ -448,7 +448,7 @@
 			int relative_bearing = bearing_to_target - recipbearing;
 			if(relative_bearing > 150 && relative_bearing < 210) sensordeaf = true;			
 			if (!sensordeaf){	
-				noisecolor=SDL_MapRGB(sonarscreen->format, 0,(int) abs((flowandambientnoise - RandInt(40))) , 0);
+				noisecolor=SDL_MapRGB(sonarscreen->format, 0,(int) fabs((flowandambientnoise - RandInt(40))) , 0);
 				DPixel(sonarscreen, nbp, 140, noisecolor);
 			}
 			else{
@@ -507,7 +507,7 @@
 			int relative_bearing = bearing_to_target - array_heading;
 			if(relative_bearing > 150 && relative_bearing < 210) sensordeaf = true;
 			if(!sensordeaf){
-				noisecolor=SDL_MapRGB(towedarrayscreen->format, 0,(int)abs((flowandambientnoise - RandInt(40))), 0);
+				noisecolor=SDL_MapRGB(towedarrayscreen->format, 0,(int)fabs((flowandambientnoise - RandInt(40))), 0);
 				DPixel(towedarrayscreen, nbp, 0, noisecolor);
 			}
 			else{
@@ -549,7 +549,7 @@
 				int relative_bearing = bearing_to_target - array_heading;
 				if(relative_bearing > 150 && relative_bearing < 210) sensordeaf = true;
 				if(!sensordeaf){
-					noisecolor=SDL_MapRGB(towedarrayscreen->format, 0,(int)abs((flowandambientnoise - RandInt(40))), 0);
+					noisecolor=SDL_MapRGB(towedarrayscreen->format, 0,(int)fabs((flowandambientnoise - RandInt(40))), 0);
 					DPixel(towedarrayscreen, nbp, 70, noisecolor);
 				}
 				else{
@@ -589,7 +589,7 @@
 				int relative_bearing = bearing_to_target - array_heading;
 				if(relative_bearing > 150 && relative_bearing < 210) sensordeaf = true;
 				if(!sensordeaf){
-					noisecolor=SDL_MapRGB(towedarrayscreen->format, 0,(int)abs((flowandambientnoise - RandInt(40))), 0);
+					noisecolor=SDL_MapRGB(towedarrayscreen->format, 0,(int)fabs((flowandambientnoise - RandInt(40))), 0);
 					DPixel(towedarrayscreen, nbp, 140, noisecolor);
 				}
 				else{
