--- src/client/OMUSIC.cpp.orig	2015-05-19 01:00:20 UTC
+++ src/client/OMUSIC.cpp
@@ -81,7 +81,8 @@ Music::Music()
 // -------- begin of function Music::~Music ---------//
 Music::~Music()
 {
-	deinit();
+	if (init_flag != 0)
+		deinit();
 }
 // -------- end of function Music::~Music ---------//
 
