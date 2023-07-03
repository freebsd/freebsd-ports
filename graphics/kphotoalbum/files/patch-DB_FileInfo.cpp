--- DB/FileInfo.cpp.orig	2023-03-25 09:46:12 UTC
+++ DB/FileInfo.cpp
@@ -80,7 +80,7 @@ void DB::FileInfo::parseEXIV2(const DB::FileName &file
 
         int orientation = 0;
         if (datum.count() > 0)
-            orientation = datum.toLong();
+            orientation = datum.toInt64();
         m_angle = orientationToAngle(orientation);
     }
 
