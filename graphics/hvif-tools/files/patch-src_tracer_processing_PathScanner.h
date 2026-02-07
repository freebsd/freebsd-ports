--- src/tracer/processing/PathScanner.h.orig	2025-12-14 12:31:58 UTC
+++ src/tracer/processing/PathScanner.h
@@ -35,7 +35,7 @@ class PathScanner { (private)
 private:
 	static const unsigned char	kPathScanDirectionLookup[16];
 	static const bool			kPathScanHolePathLookup[16];
-	static const char			kPathScanCombinedLookup[16][4][4];
+	static const signed char			kPathScanCombinedLookup[16][4][4];
 };
 
 #endif
