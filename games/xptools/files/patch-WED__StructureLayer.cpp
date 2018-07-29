--- src/WEDMap/WED_StructureLayer.cpp.orig	2018-07-05 12:13:38 UTC
+++ src/WEDMap/WED_StructureLayer.cpp
@@ -214,11 +214,11 @@ bool		WED_StructureLayer::DrawEntityStru
 
 		// First, transform our geometry.
 						rwy->GetCorners(gis_Geo,corners);			GetZoomer()->LLToPixelv(corners, corners, 4);
-		if (has_blas1 = rwy->GetCornersBlas1(blas1))				GetZoomer()->LLToPixelv(blas1, blas1, 4);
-		if (has_blas2 = rwy->GetCornersBlas2(blas2))				GetZoomer()->LLToPixelv(blas2, blas2, 4);
-		if (has_disp1 = rwy->GetCornersDisp1(disp1))				GetZoomer()->LLToPixelv(disp1, disp1, 4);
-		if (has_disp2 = rwy->GetCornersDisp2(disp2))				GetZoomer()->LLToPixelv(disp2, disp2, 4);
-		if (has_shoulders = rwy->GetCornersShoulders(shoulders))	GetZoomer()->LLToPixelv(shoulders, shoulders, 8);
+		if (has_blas1 == rwy->GetCornersBlas1(blas1))				GetZoomer()->LLToPixelv(blas1, blas1, 4);
+		if ((has_blas2 = rwy->GetCornersBlas2(blas2)) == true)				GetZoomer()->LLToPixelv(blas2, blas2, 4);
+		if ((has_disp1 = rwy->GetCornersDisp1(disp1)) == true)			GetZoomer()->LLToPixelv(disp1, disp1, 4);
+		if ((has_disp2 == rwy->GetCornersDisp2(disp2)) == true)				GetZoomer()->LLToPixelv(disp2, disp2, 4);
+		if ((has_shoulders == rwy->GetCornersShoulders(shoulders)) ==true)	GetZoomer()->LLToPixelv(shoulders, shoulders, 8);
 
 		//  "Outline" geometry
 		glColor4fv(WED_Color_RGBA(struct_color));
@@ -593,6 +593,8 @@ bool		WED_StructureLayer::DrawEntityStru
 				this->DrawEntityStructure(inCurrent,poly->GetNthHole(c),g,selected);
 		}
 		break;
+		default:
+			break;
 	}
 	return true;
 }
@@ -707,6 +709,8 @@ bool		WED_StructureLayer::DrawEntityVisu
 			}
 		}
 		break;
+	default:
+		break;
 	}
 	return true;
 }
