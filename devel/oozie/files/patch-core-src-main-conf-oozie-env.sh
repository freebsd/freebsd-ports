--- core/src/main/conf/oozie-env.sh.orig	2015-03-27 17:06:07.572531000 +0300
+++ core/src/main/conf/oozie-env.sh	2015-04-03 17:10:18.975464000 +0300
@@ -30,7 +30,8 @@
 
 # Oozie logs directory
 #
-# export OOZIE_LOG=${OOZIE_HOME}/logs
+export OOZIE_LOG=%%OOZIE_LOGDIR%%
+export CATALINA_PID=%%OOZIE_RUNDIR%%/oozied.pid
 
 # Oozie Log4J configuration file to load from Oozie configuration directory
 #
