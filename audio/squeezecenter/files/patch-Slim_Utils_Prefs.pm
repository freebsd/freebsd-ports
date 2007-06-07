
$FreeBSD$

--- Slim/Utils/Prefs.pm.orig
+++ Slim/Utils/Prefs.pm
@@ -392,6 +392,10 @@
 
 		$path = $Bin . '/Playlists';
 
+	} elsif (Slim::Utils::OSDetect::OS() eq 'unix') {
+
+		$path = "/var/db/slimserver/playlists";
+
 	} else {
 
 		$path = '';
@@ -424,7 +428,7 @@
 
 	} elsif ($os eq 'unix') {
 
-		$CacheDir = catdir($ENV{'HOME'},'Cache');
+		$CacheDir = "/var/db/slimserver/cache";
 
 	} elsif ($os eq 'win' && Slim::Utils::OSDetect::details->{'osName'} =~ /Vista/) {
 
@@ -1022,7 +1026,7 @@
 			$prefsPath = $Bin;
 		}
 	} else {
-	 	$prefsPath = $ENV{'HOME'};
+	 	$prefsPath = "/var/db/slimserver";
 	}
 	
 	$::d_prefs && msg("The default prefs directory is $prefsPath\n");
