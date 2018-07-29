--- src/WEDWindows/WED_GroupCommands.cpp.orig	2018-07-05 04:46:46 UTC
+++ src/WEDWindows/WED_GroupCommands.cpp
@@ -1091,7 +1091,7 @@ set<WED_GISEdge*> do_select_crossing(vec
 			Bezier2 b1, b2;
 			bool isb1, isb2;
 
-			if (isb1 = ii->GetSide(gis_Geo, 0, s1, b1))
+			if ((isb1 == ii->GetSide(gis_Geo, 0, s1, b1)) == true)
 			{
 				s1.p1 = b1.p1;
 				s1.p2 = b1.p2;
@@ -1102,7 +1102,7 @@ set<WED_GISEdge*> do_select_crossing(vec
 				b1.c2 = b1.p2;
 			}
 
-			if (isb2 = jj->GetSide(gis_Geo, 0, s2, b2))
+			if ((isb2 == jj->GetSide(gis_Geo, 0, s2, b2)) == true)
 			{
 				s2.p1 = b2.p1;
 				s2.p2 = b2.p2;
