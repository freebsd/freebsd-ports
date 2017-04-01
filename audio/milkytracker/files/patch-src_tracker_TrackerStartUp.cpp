--- src/tracker/TrackerStartUp.cpp.orig	2017-03-12 19:30:25 UTC
+++ src/tracker/TrackerStartUp.cpp
@@ -127,7 +127,8 @@ void Tracker::showSplash()
 		screen->paintSplash(LogoBig::rawData, LogoBig::width, LogoBig::height, LogoBig::width*3, 3, (int)shade); 		
 #endif
 		shade+=deltaT * (1.0f/6.25f);
-		deltaT = abs((signed)::PPGetTickCount() - startTime);
+		// deltaT = abs((signed)::PPGetTickCount() - startTime);
+		deltaT = abs((pp_int32)::PPGetTickCount() - startTime);
 		if (!deltaT) deltaT++;
 	}
 #if defined(__EXCLUDE_BIGLOGO__) || defined(__LOWRES__)
@@ -158,7 +159,8 @@ void Tracker::hideSplash()
 		screen->paintSplash(LogoBig::rawData, LogoBig::width, LogoBig::height, LogoBig::width*3, 3, (int)shade); 		
 #endif
 		shade-=deltaT * (1.0f/6.25f);
-		deltaT = abs((signed)::PPGetTickCount() - startTime);
+		// deltaT = abs((signed)::PPGetTickCount() - startTime);
+		deltaT = abs((pp_int32)::PPGetTickCount() - startTime);
 		if (!deltaT) deltaT++;
 	}
 	screen->clear(); 	
