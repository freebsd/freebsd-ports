--- src/Components/Covers/LocalCoverSearcher.cpp.orig	2018-09-02 20:19:55 UTC
+++ src/Components/Covers/LocalCoverSearcher.cpp
@@ -68,7 +68,7 @@ QStringList LocalSearcher::cover_paths_f
 			continue;
 		}
 
-		double d = std::abs(height - width) / (width * 1.0) + 1.0;
+		double d = std::abs(static_cast<double>(height - width)) / (width * 1.0) + 1.0;
 		double pixels = static_cast<double>(width * height);
 
 		d = (d * d * std::max(width, height)) / pixels;
