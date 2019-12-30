--- src/Components/Covers/LocalCoverSearcher.cpp.orig	2019-12-30 12:19:50 UTC
+++ src/Components/Covers/LocalCoverSearcher.cpp
@@ -75,7 +75,7 @@ QStringList LocalSearcher::cover_paths_from_path_hint(
 			continue;
 		}
 
-		double d = std::abs(height - width) / (width * 1.0) + 1.0;
+		double d = std::abs(static_cast<double>(height - width)) / (width * 1.0) + 1.0;
 		double pixels = double(width * height);
 
 		d = (d * d * std::max(width, height)) / pixels;
