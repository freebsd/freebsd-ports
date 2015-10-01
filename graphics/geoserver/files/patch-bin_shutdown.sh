--- bin/shutdown.sh.orig	2015-09-30 16:13:46 UTC
+++ bin/shutdown.sh
@@ -5,20 +5,6 @@
 # $Id$
 # -----------------------------------------------------------------------------
 
-# Make sure prerequisite environment variables are set
-if [ -z "$JAVA_HOME" ]; then
-  echo "The JAVA_HOME environment variable is not defined"
-  echo "This environment variable is needed to run this program"
-  exit 1
-fi
-if [ ! -r "$JAVA_HOME"/bin/java ]; then
-  echo "The JAVA_HOME environment variable is not defined correctly"
-  echo "This environment variable is needed to run this program"
-  exit 1
-fi
-# Set standard commands for invoking Java.
-_RUNJAVA="$JAVA_HOME"/bin/java
-
 if [ -z $GEOSERVER_HOME ]; then
   #If GEOSERVER_HOME not set then guess a few locations before giving
   # up and demanding user set it.
@@ -52,4 +38,4 @@ if [ ! -r "$GEOSERVER_HOME"/start.jar ];
 fi
 
 cd "$GEOSERVER_HOME"
-exec "$_RUNJAVA" $JAVA_OPTS -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
+exec %%JAVA%% -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
