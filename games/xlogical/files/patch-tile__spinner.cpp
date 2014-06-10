--- tile_spinner.cpp.orig	2014-06-10 17:24:39.000000000 +0000
+++ tile_spinner.cpp
@@ -21,6 +21,7 @@
 ////////////////////////////////////////////////////////////////////////
 
 
+#include <cstdlib>
 
 
 // Application Includes
@@ -46,7 +47,7 @@ Ctile_spinner::Ctile_spinner( void )
 	finished = 0;
 	finishing_hopper = -1;
 	flashOn = 0;
-	flashWait = rand( ) % 5;
+	flashWait = std::rand( ) % 5;
 
 	// Reset the hopper
 	hopper[0] = NULL;
@@ -477,7 +478,7 @@ Ctile_spinner::check_complete( void )
 				if( CURMAP->randOrder == 1 )
 				{
 					// Randomize a new color
-					CURMAP->order[2] = (color_t)(rand( )%4 + 1);
+					CURMAP->order[2] = (color_t)(std::rand( )%4 + 1);
 				} else {
 					// Set the next one to null
 					CURMAP->order[2] = NO_COLOR;
