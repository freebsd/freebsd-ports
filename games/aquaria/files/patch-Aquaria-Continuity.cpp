--- Aquaria/Continuity.cpp.orig	2016-06-19 23:56:27 UTC
+++ Aquaria/Continuity.cpp
@@ -2737,7 +2737,7 @@ void Continuity::loadFileData(int slot, 
 		}
 		if (doc.Parse(buf, size) != XML_SUCCESS)
 		{
-			errorLog("Failed to load save data: " + teh_file + " -- Error: " + doc.GetErrorStr1());
+			errorLog("Failed to load save data: " + teh_file + " -- Error: " + doc.ErrorStr());
 			return;
 		}
 	}
