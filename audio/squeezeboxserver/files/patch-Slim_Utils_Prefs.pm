
$FreeBSD$

--- Slim/Utils/Prefs.pm.orig	Thu Apr 15 18:09:50 2004
+++ Slim/Utils/Prefs.pm	Thu Apr 15 18:10:44 2004
@@ -564,7 +564,7 @@
 	} elsif (Slim::Utils::OSDetect::OS() eq 'win')  {
 		$prefsPath = $Bin;
 	} else {
-	 	$prefsPath = $ENV{'HOME'};
+	 	$prefsPath = "/var/db/slimserver";
 	}
 	
 	$::d_prefs && msg("The default prefs directory is $prefsPath\n");
