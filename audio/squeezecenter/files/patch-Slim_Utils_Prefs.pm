
$FreeBSD$

--- Slim/Utils/Prefs.pm.orig
+++ Slim/Utils/Prefs.pm
@@ -99,6 +99,10 @@
 
 		$path = $Bin . '/Playlists';
 
+	} elsif (Slim::Utils::OSDetect::OS() eq 'unix') {
+
+		$path = "/var/db/slimserver/playlists";
+
 	} else {
 
 		$path = '';
@@ -131,7 +135,7 @@
 
 	} elsif ($os eq 'unix') {
 
-		$CacheDir = $ENV{'HOME'};
+		$CacheDir = "/var/db/slimserver/cache";
 	}
 
 	my @CacheDirs = splitdir($CacheDir);
@@ -714,7 +718,7 @@
 	} elsif (Slim::Utils::OSDetect::OS() eq 'win')  {
 		$prefsPath = $Bin;
 	} else {
-	 	$prefsPath = $ENV{'HOME'};
+	 	$prefsPath = "/var/db/slimserver";
 	}
 	
 	$::d_prefs && msg("The default prefs directory is $prefsPath\n");
