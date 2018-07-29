--- src/WEDMap/WED_ATCLayer.cpp.orig	2018-07-05 15:08:08 UTC
+++ src/WEDMap/WED_ATCLayer.cpp
@@ -131,7 +131,7 @@ bool		WED_ATCLayer::DrawEntityStructure	
 		bool road = seg->AllowTrucks() && !seg->AllowAircraft();
 		bool one_way = seg->IsOneway();
 		
-		int mtr1 = 5, mtr2 = 10;
+		double mtr1 = 5, mtr2 = 10;
 		switch(icao_width) {
 		case width_A:	mtr1 = 4.5;		mtr2 = 15.0;	break;
 		case width_B:	mtr1 = 6.0;		mtr2 = 24.0;	break;
