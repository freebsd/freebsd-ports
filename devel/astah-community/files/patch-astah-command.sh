--- astah-command.sh.orig	2012-03-19 00:16:44.000000000 +0900
+++ astah-command.sh	2012-03-25 21:36:30.000000000 +0900
@@ -22,11 +22,11 @@
 #export PATH=$PATH:$JAVA_HOME/bin
 
 #ASTAH_HOME=/usr/lib/astah_community
-ASTAH_HOME=`pwd`
+ASTAH_HOME=%%DATADIR%%
 
 INITIAL_HEAP_SIZE=64m
 MAXIMUM_HEAP_SIZE=1024m
 
 JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
 
-java $JAVA_OPTS -cp "$ASTAH_HOME/astah-community.jar" com.change_vision.jude.cmdline.JudeCommandRunner "$@"
+%%JAVA_HOME%%/bin/java $JAVA_OPTS -cp "$ASTAH_HOME/astah-community.jar" com.change_vision.jude.cmdline.JudeCommandRunner "$@"
