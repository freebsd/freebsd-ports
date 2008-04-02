
$FreeBSD$

--- Slim/Utils/Prefs.pm.orig
+++ Slim/Utils/Prefs.pm
@@ -235,7 +235,7 @@
 								   ],
 		'titleFormatWeb'        => 1,
 		# Server Settings - UserInterface
-		'skin'                  => 'Default',
+		'skin'                  => '%%DEFAULT_SKIN%%',
 		'itemsPerPage'          => 50,
 		'refreshRate'           => 30,
 		'coverArt'              => '',
