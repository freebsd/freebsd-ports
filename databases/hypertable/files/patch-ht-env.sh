--- bin/ht-env.sh	2010-05-06 12:24:43.000000000 +0000
+++ bin/ht-env.sh	2010-05-06 12:25:00.000000000 +0000
@@ -179,9 +179,6 @@
 
 # Sanity check
 [ "$HYPERTABLE_HOME" ] || die "ERROR: HYPERTABLE_HOME is not set"
-versionre='/([0-9]+\.[0-9]+\.[0-9]+\.[0-9]+(\.[a-fA-F0-9]+)?|current)$'
-[[ $HYPERTABLE_HOME =~ $versionre ]] ||
-    die "ERROR: Invalid HYPERTABLE_HOME: $HYPERTABLE_HOME"
 
 # Make sure log and run directories exist
 [ -d $HYPERTABLE_HOME/run ] || mkdir $HYPERTABLE_HOME/run
