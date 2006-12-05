--- src/tracks/instrument_track.cpp.orig	Mon Dec  4 15:22:32 2006
+++ src/tracks/instrument_track.cpp	Tue Dec  5 09:49:12 2006
@@ -919,7 +919,7 @@
 		trackContentObject * tco = getTCO( _tco_num );
 		tcos.push_back( tco );
 		bb_track = bbTrack::findBBTrack( _tco_num, eng() );
-		if( !( bb_track->automationDisabled( this )
+		if( bb_track != NULL && !( bb_track->automationDisabled( this )
 				|| dynamic_cast<pattern *>( tco )->empty() ) )
 		{
 			sendMidiTime( _start );
