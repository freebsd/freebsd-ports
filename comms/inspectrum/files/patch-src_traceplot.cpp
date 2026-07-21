--- src/traceplot.cpp.orig	2026-07-21 08:44:18 UTC
+++ src/traceplot.cpp
@@ -32,7 +32,7 @@ void TracePlot::paintMid(QPainter &painter, QRect &rec
 {
     if (sampleRange.length() == 0) return;
 
-    int samplesPerColumn = std::max(1UL, sampleRange.length() / rect.width());
+    int samplesPerColumn = std::max(static_cast<size_t>(1), sampleRange.length() / rect.width());
     int samplesPerTile = tileWidth * samplesPerColumn;
     size_t tileID = sampleRange.minimum / samplesPerTile;
     size_t tileOffset = sampleRange.minimum % samplesPerTile; // Number of samples to skip from first image tile
