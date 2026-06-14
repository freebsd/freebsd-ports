diff --git src/Mod/TechDraw/Gui/CommandCreateDims.cpp src/Mod/TechDraw/Gui/CommandCreateDims.cpp
index 01df60faa1..e0f677f622 100644
--- src/Mod/TechDraw/Gui/CommandCreateDims.cpp
+++ src/Mod/TechDraw/Gui/CommandCreateDims.cpp
@@ -1103,7 +1103,7 @@ protected:
             TechDraw::pointPair pp = dim->getLinearPoints();
             float dx = pp.first().x - pp.second().x;
             float dy = pp.first().y - pp.second().y;
-            int alpha = std::round(Base::toDegrees(std::abs<float>(std::atan(type == "DistanceY" ? (dx / dy) : (dy / dx)))));
+            int alpha = std::round(Base::toDegrees(std::abs<float>((float) std::atan(type == "DistanceY" ? (dx / dy) : (dy / dx)))));
             std::string sAlpha = std::to_string(alpha);
             std::string formatSpec = dim->FormatSpec.getStrValue();
             formatSpec = formatSpec + " x" + sAlpha + "°";
