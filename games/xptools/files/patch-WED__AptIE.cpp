--- src/WEDImportExport/WED_AptIE.cpp.orig	2018-07-05 06:19:23 UTC
+++ src/WEDImportExport/WED_AptIE.cpp
@@ -309,7 +309,7 @@ void	AptExportRecursive(WED_Thing * what
 	 * a bogus export. */
 	if(dynamic_cast<WED_OverlayImage *>(what)) return;
 
-	if (apt = dynamic_cast<WED_Airport *>(what))
+	if ((apt = dynamic_cast<WED_Airport *>(what)) != NULL)
 	{
 		apts.push_back(AptInfo_t());
 		apt->Export(apts.back());
@@ -338,11 +338,11 @@ void	AptExportRecursive(WED_Thing * what
 		
 #endif
 	}
-	else if (bcn = dynamic_cast<WED_AirportBeacon *>(what))
+	else if ((bcn = dynamic_cast<WED_AirportBeacon *>(what)) != NULL)
 	{
 		bcn->Export(apts.back().beacon);
 	}
-	else if (bou = dynamic_cast<WED_AirportBoundary *>(what))
+	else if ((bou == dynamic_cast<WED_AirportBoundary *>(what)) != 0)
 	{
 		apts.back().boundaries.push_back(AptBoundary_t());
 		bou->Export(apts.back().boundaries.back());
@@ -357,44 +357,44 @@ void	AptExportRecursive(WED_Thing * what
 		return;	// bail out - we already got the children.
 
 	}
-	else if (cha = dynamic_cast<WED_AirportChain *>(what))
+	else if ((cha = dynamic_cast<WED_AirportChain *>(what)) != NULL)
 	{
 		apts.back().lines.push_back(AptMarking_t());
 		cha->Export(apts.back().lines.back());
 		ExportLinearPath(cha, apts.back().lines.back().area);
 		return;	// don't waste time with nodes - for speed
 	}
-	else if (sgn = dynamic_cast<WED_AirportSign *>(what))
+	else if ((sgn = dynamic_cast<WED_AirportSign *>(what)) != NULL)
 	{
 		apts.back().signs.push_back(AptSign_t());
 		sgn->Export(apts.back().signs.back());
 	}
-	else if (hel = dynamic_cast<WED_Helipad *>(what))
+	else if ((hel = dynamic_cast<WED_Helipad *>(what)) != NULL)
 	{
 		apts.back().helipads.push_back(AptHelipad_t());
 		hel->Export(apts.back().helipads.back());
 	}
-	else if (lit = dynamic_cast<WED_LightFixture *>(what))
+	else if ((lit = dynamic_cast<WED_LightFixture *>(what)) != NULL)
 	{
 		apts.back().lights.push_back(AptLight_t());
 		lit->Export(apts.back().lights.back());
 	}
-	else if (ram = dynamic_cast<WED_RampPosition *>(what))
+	else if ((ram = dynamic_cast<WED_RampPosition *>(what)) != NULL)
 	{
 		apts.back().gates.push_back(AptGate_t());
 		ram->Export(apts.back().gates.back());
 	}
-	else if (rwy = dynamic_cast<WED_Runway *>(what))
+	else if ((rwy = dynamic_cast<WED_Runway *>(what)) != NULL)
 	{
 		apts.back().runways.push_back(AptRunway_t());
 		rwy->Export(apts.back().runways.back());
 	}
-	else if (sea = dynamic_cast<WED_Sealane *>(what))
+	else if ((sea = dynamic_cast<WED_Sealane *>(what)) != NULL)
 	{
 		apts.back().sealanes.push_back(AptSealane_t());
 		sea->Export(apts.back().sealanes.back());
 	}
-	else if (tax = dynamic_cast<WED_Taxiway *>(what))
+	else if ((tax = dynamic_cast<WED_Taxiway *>(what)) != NULL)
 	{
 		apts.back().taxiways.push_back(AptTaxiway_t());
 		tax->Export(apts.back().taxiways.back());
@@ -409,47 +409,47 @@ void	AptExportRecursive(WED_Thing * what
 		}
 		return; // bail out - we already got the children
 	}
-	else if (twr = dynamic_cast<WED_TowerViewpoint *>(what))
+	else if ((twr = dynamic_cast<WED_TowerViewpoint *>(what)) != NULL)
 	{
 		twr->Export(apts.back().tower);
 	}
-	else if (win = dynamic_cast<WED_Windsock *>(what))
+	else if ((win = dynamic_cast<WED_Windsock *>(what)) != NULL)
 	{
 		apts.back().windsocks.push_back(AptWindsock_t());
 		win->Export(apts.back().windsocks.back());
 	}
-	else if (atc = dynamic_cast<WED_ATCFrequency *>(what))
+	else if ((atc = dynamic_cast<WED_ATCFrequency *>(what)) != NULL )
 	{
 		apts.back().atc.push_back(AptATCFreq_t());
 		atc->Export(apts.back().atc.back());
 	}
 #if AIRPORT_ROUTING	
-	else if(flw = dynamic_cast<WED_ATCFlow *>(what))
+	else if((flw = dynamic_cast<WED_ATCFlow *>(what)) != NULL)
 	{
 		apts.back().flows.push_back(AptFlow_t());
 		flw->Export(apts.back().flows.back());
 	}
-	else if(use = dynamic_cast<WED_ATCRunwayUse *>(what))
+	else if((use = dynamic_cast<WED_ATCRunwayUse *>(what)) != NULL)
 	{
 		apts.back().flows.back().runway_rules.push_back(AptRunwayRule_t());
 		use->Export(apts.back().flows.back().runway_rules.back());
 	}
-	else if(tim = dynamic_cast<WED_ATCTimeRule *>(what))
+	else if((tim = dynamic_cast<WED_ATCTimeRule *>(what)) != NULL)
 	{
 		apts.back().flows.back().time_rules.push_back(AptTimeRule_t());
 		tim->Export(apts.back().flows.back().time_rules.back());
 	}
-	else if(wnd = dynamic_cast<WED_ATCWindRule *>(what))
+	else if((wnd = dynamic_cast<WED_ATCWindRule *>(what)) != NULL)
 	{
 		apts.back().flows.back().wind_rules.push_back(AptWindRule_t());
 		wnd->Export(apts.back().flows.back().wind_rules.back());
 	}
-	else if(trk = dynamic_cast<WED_TruckParkingLocation*>(what))
+	else if((trk = dynamic_cast<WED_TruckParkingLocation*>(what)) != NULL)
 	{
 		apts.back().truck_parking.push_back(AptTruckParking_t());
 		trk->Export(apts.back().truck_parking.back());
 	}
-	else if(dst = dynamic_cast<WED_TruckDestination*>(what))
+	else if((dst == dynamic_cast<WED_TruckDestination*>(what)) != 0)
 	{
 		apts.back().truck_destinations.push_back(AptTruckDestination_t());
 		dst->Export(apts.back().truck_destinations.back());
