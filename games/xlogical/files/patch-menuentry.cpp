--- menuentry.cpp.orig	2007-11-06 00:04:44.000000000 +0100
+++ menuentry.cpp	2007-11-06 00:06:49.000000000 +0100
@@ -104,14 +104,14 @@
 	if (fOnOff)
 	{
 		font->render_string(
-			"*",
+			(char *)"*",
 			fX + graphDriver->graph_hi_font( )->stringLen( const_cast<char *>(fText.c_str() ) ),
 			fY );
 	} else {
 		graphDriver->graph_clear_rect(
 			fX + graphDriver->graph_hi_font()->stringLen( const_cast<char *>(fText.c_str() ) ),
 			fY,
-			graphDriver->graph_hi_font()->stringLen( "*" ),
+			graphDriver->graph_hi_font()->stringLen((char *) "*" ),
 			graphDriver->graph_hi_font()->get_height() );
 	}
 
@@ -131,7 +131,7 @@
 	graphDriver->graph_clear_rect(
 		fX + graphDriver->graph_hi_font()->stringLen( const_cast<char *>(fText.c_str() ) ),
 		fY,
-		graphDriver->graph_hi_font()->stringLen( "*" ),
+		graphDriver->graph_hi_font()->stringLen((char *) "*" ),
 		graphDriver->graph_hi_font()->get_height() );
 
 	switch( aKeyval )
