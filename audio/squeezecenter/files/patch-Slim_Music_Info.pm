
$FreeBSD$

--- Slim/Music/Info.pm.orig	Thu Apr 15 20:57:32 2004
+++ Slim/Music/Info.pm	Thu Apr 15 20:57:49 2004
@@ -208,7 +208,7 @@
 
 	# TODO: MacOS X should really store this in a visible, findable place.
 	if (Slim::Utils::OSDetect::OS() eq 'unix') {
-		$dbname = '.slimserver.db';
+		$dbname = 'slimserver.db';
 	} else {
 		$dbname ='slimserver.db';
 	}
