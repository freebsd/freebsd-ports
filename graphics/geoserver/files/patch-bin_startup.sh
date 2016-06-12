--- bin/startup.sh.orig	2016-06-11 18:51:47 UTC
+++ bin/startup.sh
@@ -74,4 +74,4 @@ cd "$GEOSERVER_HOME"
 echo "GEOSERVER DATA DIR is $GEOSERVER_DATA_DIR"
 #added headless to true by default, if this messes anyone up let the list
 #know and we can change it back, but it seems like it won't hurt -ch
-exec "$_RUNJAVA" $JAVA_OPTS -DGEOSERVER_DATA_DIR="$GEOSERVER_DATA_DIR" -Djava.awt.headless=true -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar 
+exec %%JAVA%% -DGEOSERVER_DATA_DIR=$GEOSERVER_DATA_DIR -Djava.awt.headless=true -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar
