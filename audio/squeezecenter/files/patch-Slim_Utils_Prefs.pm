
$FreeBSD$

--- Slim/Utils/Prefs.pm.orig
+++ Slim/Utils/Prefs.pm
@@ -59,6 +59,8 @@
 		$path = $ENV{'HOME'} . '/Music/Playlists';
 	} elsif (Slim::Utils::OSDetect::OS() eq 'win') {
 		$path = $Bin . '/Playlists';
+	} elsif (Slim::Utils::OSDetect::OS() eq 'unix') {
+		$path = "/var/db/slimserver/playlists";
 	} else {
 		$path = '';
 	}
@@ -72,7 +74,7 @@
 	if ($os eq 'mac') {
 		$CacheDir = catdir($ENV{'HOME'}, '/Library/Caches/SlimServer');
 	} elsif ($os eq 'unix') {
-		$CacheDir = $ENV{'HOME'};
+		$CacheDir = "/var/db/slimserver/cache";
 	}
 	my @CacheDirs = splitdir($CacheDir);
 	pop @CacheDirs;
@@ -605,7 +607,7 @@
 	} elsif (Slim::Utils::OSDetect::OS() eq 'win')  {
 		$prefsPath = $Bin;
 	} else {
-	 	$prefsPath = $ENV{'HOME'};
+	 	$prefsPath = "/var/db/slimserver";
 	}
 	
 	$::d_prefs && msg("The default prefs directory is $prefsPath\n");
