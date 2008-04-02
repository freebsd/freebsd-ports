
$FreeBSD$

--- Slim/Utils/Prefs/OldPrefs.pm.orig
+++ Slim/Utils/Prefs/OldPrefs.pm
@@ -117,7 +117,11 @@
 
 		$oldPrefs = catdir($ENV{'HOME'}, 'slimserver.pref');
 
-	} else {
+	} elsif (-r '/var/db/slimserver/slimserver.conf') {
+
+		$oldPrefs = '/var/db/slimserver/slimserver.conf';
+
+	}else {
 
 		$log->warn("no old preference file found - using default preferences");
 
