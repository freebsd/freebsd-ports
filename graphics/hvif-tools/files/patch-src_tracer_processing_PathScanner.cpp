--- src/tracer/processing/PathScanner.cpp.orig	2025-12-14 12:31:31 UTC
+++ src/tracer/processing/PathScanner.cpp
@@ -16,7 +16,7 @@ const bool PathScanner::kPathScanHolePathLookup[16] = 
 	false, false, false, true, false, true, true, false
 };
 
-const char PathScanner::kPathScanCombinedLookup[16][4][4] = {
+const signed char PathScanner::kPathScanCombinedLookup[16][4][4] = {
 	{{-1,-1,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,-1}, {-1,-1,-1,-1}}, // 0
 	{{ 0, 1, 0,-1}, {-1,-1,-1,-1}, {-1,-1,-1,-1}, { 0, 2,-1, 0}}, // 1
 	{{-1,-1,-1,-1}, {-1,-1,-1,-1}, { 0, 1, 0,-1}, { 0, 0, 1, 0}}, // 2
@@ -137,7 +137,7 @@ PathScanner::ScanPaths(std::vector<std::vector<int> >&
 						break;
 					}
 
-					const char* lookupRow = kPathScanCombinedLookup[code][direction];
+					const signed char* lookupRow = kPathScanCombinedLookup[code][direction];
 
 					if (lookupRow[1] < 0) {
 						pathFinished = true;
