--- astah-command.sh.orig	2013-03-08 06:02:20.000000000 +0900
+++ astah-command.sh	2013-03-15 10:50:23.000000000 +0900
@@ -22,7 +22,7 @@
 #export PATH=$PATH:$JAVA_HOME/bin
 
 #ASTAH_HOME=/usr/lib/astah_community
-ASTAH_HOME=`dirname "$0"`
+ASTAH_HOME=%%DATADIR%%
 
 INITIAL_HEAP_SIZE=64m
 MAXIMUM_HEAP_SIZE=1024m
@@ -30,4 +30,4 @@
 JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
 #JAVA_OPTS="\$JAVA_OPTS -DrootLevel=DEBUG"
 
-java $JAVA_OPTS -cp "$ASTAH_HOME/astah-community.jar" com.change_vision.jude.cmdline.JudeCommandRunner "$@"
+%%JAVA_HOME%%/bin/java $JAVA_OPTS -cp "$ASTAH_HOME/astah-community.jar" com.change_vision.jude.cmdline.JudeCommandRunner "$@"
