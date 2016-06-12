--- bin/shutdown.sh.orig	2016-05-28 00:30:28 UTC
+++ bin/shutdown.sh
@@ -60,4 +60,4 @@ if [ ! -r "$GEOSERVER_HOME"/start.jar ];
 fi
 
 cd "$GEOSERVER_HOME"
-exec "$_RUNJAVA" $JAVA_OPTS -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
+exec %%JAVA%% -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
