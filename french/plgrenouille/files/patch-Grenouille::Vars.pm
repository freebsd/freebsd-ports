--- Grenouille/Vars.pm.orig	Wed Dec  5 23:42:30 2001
+++ Grenouille/Vars.pm	Thu Mar  4 03:59:13 2004
@@ -8,6 +8,7 @@
 use vars qw(@ISA @EXPORT_OK
             $MYRC $DATAPATH $DOWNLOADFILE $UPLOADFILE $QUEUEFILE 
             $LASTCONFIGFILE $LASTVERSIONFILE $PIDFILE $LOGFILE
+            $BEFOREFILE $AFTERFILE
             $ASAP $SEC $MIN $HOUR $DAY @MONTHS
             $USER
             %VERSION %DEBUG
@@ -15,6 +16,7 @@
 @ISA=qw(Exporter);
 @EXPORT_OK=qw($MYRC $DATAPATH $DOWNLOADFILE $UPLOADFILE $QUEUEFILE
               $LASTCONFIGFILE $LASTVERSIONFILE $PIDFILE $LOGFILE 
+              $BEFOREFILE $AFTERFILE
               $ASAP $SEC $MIN $HOUR $DAY @MONTHS
               $USER
               %VERSION %DEBUG
@@ -30,15 +32,17 @@
              'system' => ($^O eq 'win32' ? 'windows' : $^O) );
 
 # Paths
-$MYRC ||= '/etc/grenouillerc';
-$DATAPATH ||= '/var/spool/plgrenouille';
+$MYRC ||= '%%PREFIX%%/etc/grenouillerc';
+$BEFOREFILE ||= '%%PREFIX%%/etc/plgrenouille-before';
+$AFTERFILE ||= '%%PREFIX%%/etc/plgrenouille-after';
+$DATAPATH ||= '%%SPOOL_DIR%%';
 $DOWNLOADFILE ||= "$DATAPATH/downloadfile";
 $UPLOADFILE ||= "$DATAPATH/uploadfile";
 $QUEUEFILE ||= "$DATAPATH/queued_results.txt";
 $LASTCONFIGFILE ||= "$DATAPATH/last_configuration.txt";
 $LASTVERSIONFILE ||= "$DATAPATH/last_known_version.txt";
-$PIDFILE ||= "/var/run/plgrenouille.pid";
-$LOGFILE ||= "/var/log/plgrenouille.log";
+$PIDFILE ||= "%%RUN_DIR%%/plgrenouille.pid";
+$LOGFILE ||= "%%LOG_DIR%%/plgrenouille.log";
 
 # Time constants
 $ASAP ||= 0;
@@ -48,7 +52,7 @@
 $DAY ||= 24 * $HOUR;
 @MONTHS = qw(Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec);
 
-$USER ||= 'daemon';
+$USER ||= '%%SPOOL_USER%%';
 
 # Debugging
 # what features do we want to debug ?
