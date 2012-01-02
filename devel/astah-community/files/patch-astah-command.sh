--- astah-command.sh.orig	2011-11-15 14:35:20.000000000 +0900
+++ astah-command.sh	2012-01-02 07:58:58.000000000 +0900
@@ -22,11 +22,11 @@
 #export PATH=$PATH:$JAVA_HOME/bin
 
 #ASTAH_HOME=/usr/lib/astah_professional
-ASTAH_HOME=`pwd`
+ASTAH_HOME=%%DATADIR%%
 
 INITIAL_HEAP_SIZE=64m
 MAXIMUM_HEAP_SIZE=1024m
 
 JAVA_OPTS="-Xms$INITIAL_HEAP_SIZE -Xmx$MAXIMUM_HEAP_SIZE"
 
-java $JAVA_OPTS -cp $ASTAH_HOME/astah-community.jar com.change_vision.jude.cmdline.JudeCommandRunner "$@"
+LD_LIBRARY_PATH=%%JAVA_HOME%%/jre/lib/i386/jli %%JAVA_HOME%%/bin/java $JAVA_OPTS -cp $ASTAH_HOME/astah-community.jar com.change_vision.jude.cmdline.JudeCommandRunner "$@"
