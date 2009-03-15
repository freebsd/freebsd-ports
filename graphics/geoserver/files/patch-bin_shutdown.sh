--- bin/shutdown.sh.orig	2008-03-11 17:53:00.000000000 +0100
+++ bin/shutdown.sh	2008-03-11 17:53:22.000000000 +0100
@@ -5,20 +5,6 @@
 # $Id: shutdown.sh 7290 2007-07-23 18:57:27Z jdeolive $
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
@@ -52,4 +38,4 @@
 fi
 
 cd "$GEOSERVER_HOME"
-exec "$_RUNJAVA" -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
+exec %%JAVA%% -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
