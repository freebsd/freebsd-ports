--- slimserver-9977737/Slim/Utils/Log.pm.orig	2025-03-09 06:30:53 UTC
+++ slimserver-9977737/Slim/Utils/Log.pm
@@ -173,7 +173,7 @@ sub init {
 	# Make sure recreate option is set if user has an existing log.conf
 	if ( !main::ISWINDOWS && !$ENV{NYTPROF} ) {
 		$config{'log4perl.appender.server.recreate'}              = 1;
-		$config{'log4perl.appender.server.recreate_check_signal'} = 'USR1';
+		$config{'log4perl.appender.server.recreate_check_signal'} = 'HUP';
 	}
 	else {
 		$config{'log4perl.appender.server.recreate'}              = 0;
@@ -1018,7 +1018,7 @@ sub _defaultAppenders {
 
 	if ( !main::ISWINDOWS && !$ENV{NYTPROF} ) {
 		$defaultAppenders{server}->{recreate}              = 1;
-		$defaultAppenders{server}->{recreate_check_signal} = 'USR1';
+		$defaultAppenders{server}->{recreate_check_signal} = 'HUP';
 	}
 
 	return $class->_fixupAppenders(\%defaultAppenders);
