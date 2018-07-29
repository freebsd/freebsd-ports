--- src/WEDMap/WED_PreviewLayer.cpp.orig	2018-07-05 13:03:46 UTC
+++ src/WEDMap/WED_PreviewLayer.cpp
@@ -362,9 +362,9 @@ struct	preview_runway : public WED_Previ
 
 		// First, transform our geometry.
 						rwy->GetCorners(gis_Geo,corners);			zoomer->LLToPixelv(corners, corners, 4);
-		if (has_blas1 = rwy->GetCornersBlas1(blas1))				zoomer->LLToPixelv(blas1, blas1, 4);
-		if (has_blas2 = rwy->GetCornersBlas2(blas2))				zoomer->LLToPixelv(blas2, blas2, 4);
-		if (has_shoulders = rwy->GetCornersShoulders(shoulders))	zoomer->LLToPixelv(shoulders, shoulders, 8);
+		if (has_blas1 == rwy->GetCornersBlas1(blas1))				zoomer->LLToPixelv(blas1, blas1, 4);
+		if (has_blas2 == rwy->GetCornersBlas2(blas2))				zoomer->LLToPixelv(blas2, blas2, 4);
+		if (has_shoulders == rwy->GetCornersShoulders(shoulders))	zoomer->LLToPixelv(shoulders, shoulders, 8);
 
 		if (mPavementAlpha > 0.0f)
 		{
