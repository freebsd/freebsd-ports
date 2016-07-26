--- src/tracker/TrackerStartUp.cpp.orig	2013-11-09 00:12:01 UTC
+++ src/tracker/TrackerStartUp.cpp
@@ -126,7 +126,7 @@ void Tracker::showSplash()
 		screen->paintSplash(LogoBig::rawData, LogoBig::width, LogoBig::height, LogoBig::width*3, 3, (int)shade); 		
 #endif
 		shade+=deltaT * (1.0f/6.25f);
-		deltaT = abs(::PPGetTickCount() - startTime);
+		deltaT = abs((pp_int32)::PPGetTickCount() - startTime);
 		if (!deltaT) deltaT++;
 	}
 #if defined(__EXCLUDE_BIGLOGO__) || defined(__LOWRES__)
@@ -157,7 +157,7 @@ void Tracker::hideSplash()
 		screen->paintSplash(LogoBig::rawData, LogoBig::width, LogoBig::height, LogoBig::width*3, 3, (int)shade); 		
 #endif
 		shade-=deltaT * (1.0f/6.25f);
-		deltaT = abs(::PPGetTickCount() - startTime);
+		deltaT = abs((pp_int32)::PPGetTickCount() - startTime);
 		if (!deltaT) deltaT++;
 	}
 	screen->clear(); 	
