
$FreeBSD$

--- Slim/Music/Info.pm.orig	Fri Jul  2 18:46:03 2004
+++ Slim/Music/Info.pm	Sun Aug 15 15:06:37 2004
@@ -312,7 +312,7 @@
 	# Setup $dbname regardless of if we're caching as cache could be turned on later
 
 	if (Slim::Utils::OSDetect::OS() eq 'unix') {
-		$dbname = '.slimserver.db';
+		$dbname = 'slimserver.db';
 	} else {
 		$dbname ='slimserver.db';
 	}
