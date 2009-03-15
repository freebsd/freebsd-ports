--- bin/startup.sh.orig	2008-03-11 17:52:11.000000000 +0100
+++ bin/startup.sh	2008-03-11 17:52:51.000000000 +0100
@@ -5,20 +5,6 @@
 # $Id: startup.sh 7290 2007-07-23 18:57:27Z jdeolive $
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
@@ -66,4 +52,4 @@
 echo "GEOSERVER DATA DIR is $GEOSERVER_DATA_DIR"
 #added headless to true by default, if this messes anyone up let the list
 #know and we can change it back, but it seems like it won't hurt -ch
-exec "$_RUNJAVA" -DGEOSERVER_DATA_DIR=$GEOSERVER_DATA_DIR -Djava.awt.headless=true -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar 
+exec %%JAVA%% -DGEOSERVER_DATA_DIR=$GEOSERVER_DATA_DIR -Djava.awt.headless=true -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar
