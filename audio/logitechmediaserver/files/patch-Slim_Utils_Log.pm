--- Slim/Utils/Log.pm.orig	2016-09-30 13:54:28 UTC
+++ Slim/Utils/Log.pm
@@ -134,7 +134,7 @@ sub init {
 	# Make sure recreate option is set if user has an existing log.conf
 	if ( !main::ISWINDOWS && !$ENV{NYTPROF} ) {
 		$config{'log4perl.appender.server.recreate'}              = 1;
-		$config{'log4perl.appender.server.recreate_check_signal'} = 'USR1';
+		$config{'log4perl.appender.server.recreate_check_signal'} = 'HUP';
 	}
 	else {
 		$config{'log4perl.appender.server.recreate'}              = 0;
@@ -1005,7 +1005,7 @@ sub _defaultAppenders {
 
 	if ( !main::ISWINDOWS && !$ENV{NYTPROF} ) {
 		$defaultAppenders{server}->{recreate}              = 1;
-		$defaultAppenders{server}->{recreate_check_signal} = 'USR1';
+		$defaultAppenders{server}->{recreate_check_signal} = 'HUP';
 	}
 
 	return $class->_fixupAppenders(\%defaultAppenders);
