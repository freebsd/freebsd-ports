--- Slim/Utils/Log.pm	2010-04-01 13:21:54.000000000 +0100
+++ Slim/Utils/Log.pm	2010-06-07 09:08:34.000000000 +0100
@@ -134,7 +134,7 @@
 	# Make sure recreate option is set if user has an existing log.conf
 	if ( !main::ISWINDOWS && !$ENV{NYTPROF} ) {
 		$config{'log4perl.appender.server.recreate'}              = 1;
-		$config{'log4perl.appender.server.recreate_check_signal'} = 'USR1';
+		$config{'log4perl.appender.server.recreate_check_signal'} = 'HUP';
 	}
 	
 	# Change to syslog if requested
@@ -985,7 +985,7 @@
 
 	if ( !main::ISWINDOWS && !$ENV{NYTPROF} ) {
 		$defaultAppenders{server}->{recreate}              = 1;
-		$defaultAppenders{server}->{recreate_check_signal} = 'USR1';
+		$defaultAppenders{server}->{recreate_check_signal} = 'HUP';
 	}
 
 	return $class->_fixupAppenders(\%defaultAppenders);
