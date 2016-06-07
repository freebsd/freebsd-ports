--- src/ui/tools/flood-tool.cpp.orig	2014-11-30 18:45:32 UTC
+++ src/ui/tools/flood-tool.cpp
@@ -252,13 +252,13 @@ static bool compare_pixels(guint32 check
     
     switch (method) {
         case FLOOD_CHANNELS_ALPHA:
-            return abs(static_cast<int>(ac) - ao) <= threshold;
+            return abs(static_cast<int>(ac) - static_cast<int>(ao)) <= threshold;
         case FLOOD_CHANNELS_R:
-            return abs(static_cast<int>(ac ? unpremul_alpha(rc, ac) : 0) - (ao ? unpremul_alpha(ro, ao) : 0)) <= threshold;
+            return abs(static_cast<int>(ac ? unpremul_alpha(rc, ac) : 0) - static_cast<int>(ao ? unpremul_alpha(ro, ao) : 0)) <= threshold;
         case FLOOD_CHANNELS_G:
-            return abs(static_cast<int>(ac ? unpremul_alpha(gc, ac) : 0) - (ao ? unpremul_alpha(go, ao) : 0)) <= threshold;
+            return abs(static_cast<int>(ac ? unpremul_alpha(gc, ac) : 0) - static_cast<int>(ao ? unpremul_alpha(go, ao) : 0)) <= threshold;
         case FLOOD_CHANNELS_B:
-            return abs(static_cast<int>(ac ? unpremul_alpha(bc, ac) : 0) - (ao ? unpremul_alpha(bo, ao) : 0)) <= threshold;
+            return abs(static_cast<int>(ac ? unpremul_alpha(bc, ac) : 0) - static_cast<int>(ao ? unpremul_alpha(bo, ao) : 0)) <= threshold;
         case FLOOD_CHANNELS_RGB:
             guint32 amc, rmc, bmc, gmc;
             //amc = 255*255 - (255-ac)*(255-ad); amc = (amc + 127) / 255;
@@ -268,9 +268,9 @@ static bool compare_pixels(guint32 check
             gmc = (255-ac)*gd + 255*gc; gmc = (gmc + 127) / 255;
             bmc = (255-ac)*bd + 255*bc; bmc = (bmc + 127) / 255;
 
-            diff += abs(static_cast<int>(amc ? unpremul_alpha(rmc, amc) : 0) - (amop ? unpremul_alpha(rmop, amop) : 0));
-            diff += abs(static_cast<int>(amc ? unpremul_alpha(gmc, amc) : 0) - (amop ? unpremul_alpha(gmop, amop) : 0));
-            diff += abs(static_cast<int>(amc ? unpremul_alpha(bmc, amc) : 0) - (amop ? unpremul_alpha(bmop, amop) : 0));
+            diff += abs(static_cast<int>(amc ? unpremul_alpha(rmc, amc) : 0) - static_cast<int>(amop ? unpremul_alpha(rmop, amop) : 0));
+            diff += abs(static_cast<int>(amc ? unpremul_alpha(gmc, amc) : 0) - static_cast<int>(amop ? unpremul_alpha(gmop, amop) : 0));
+            diff += abs(static_cast<int>(amc ? unpremul_alpha(bmc, amc) : 0) - static_cast<int>(amop ? unpremul_alpha(bmop, amop) : 0));
             return ((diff / 3) <= ((threshold * 3) / 4));
         
         case FLOOD_CHANNELS_H:
