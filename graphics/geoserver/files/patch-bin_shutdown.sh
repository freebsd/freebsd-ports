--- bin/shutdown.sh.orig	2021-09-14 02:52:16 UTC
+++ bin/shutdown.sh
@@ -65,4 +65,4 @@ if [ ! -r "${GEOSERVER_HOME}/start.jar" ]; then
 fi
 
 cd "${GEOSERVER_HOME}" || exit 1
-exec "${_RUNJAVA}" "${JAVA_OPTS:--DnoJavaOpts}" -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
+exec %%JAVA%% -DSTOP.PORT=8079 -DSTOP.KEY=geoserver -jar start.jar --stop
