--- ext/xbrz/xbrz.cpp.orig	2015-02-26 20:05:06 UTC
+++ ext/xbrz/xbrz.cpp
@@ -616,23 +616,21 @@ void scalePixel(const Kernel_3x3& ker,
 		auto eq   = [&](uint32_t col1, uint32_t col2) { return ColorDistance::dist(col1, col2, cfg.luminanceWeight_) < cfg.equalColorTolerance_; };
 		auto dist = [&](uint32_t col1, uint32_t col2) { return ColorDistance::dist(col1, col2, cfg.luminanceWeight_); };
 
-		const bool doLineBlend = [&]() -> bool
-		{
+		bool doLineBlend;
+
 			if (getBottomR(blend) >= BLEND_DOMINANT)
-				return true;
+				doLineBlend = true;
 
 			//make sure there is no second blending in an adjacent rotation for this pixel: handles insular pixels, mario eyes
-			if (getTopR(blend) != BLEND_NONE && !eq(e, g)) //but support double-blending for 90° corners
-				return false;
-			if (getBottomL(blend) != BLEND_NONE && !eq(e, c))
-				return false;
-
+			else if (getTopR(blend) != BLEND_NONE && !eq(e, g)) //but support double-blending for 90° corners
+				doLineBlend = false;
+			else if (getBottomL(blend) != BLEND_NONE && !eq(e, c))
+				doLineBlend = false;
 			//no full blending for L-shapes; blend corner only (handles "mario mushroom eyes")
-			if (eq(g, h) &&  eq(h , i) && eq(i, f) && eq(f, c) && !eq(e, i))
-				return false;
-
-			return true;
-		}();
+			else if (eq(g, h) && eq(h, i) && eq(i, f) && eq(f, c) && !eq(e, i))
+				doLineBlend = false;
+			else
+				doLineBlend = true;
 
 		const uint32_t px = dist(e, f) <= dist(e, h) ? f : h; //choose most similar color
 
