--- bin/startup.sh.orig	2008-05-30 08:34:03.000000000 +0200
+++ bin/startup.sh	2008-06-01 15:44:53.000000000 +0200
@@ -1,33 +1,13 @@
 #! /bin/sh
 
 
-# add the libraries to the IREPORT_CLASSPATH.
-# EXEDIR is the directory where this executable is.
-EXEDIR=${0%/*}
-DIRLIBS=${EXEDIR}/../lib/*.jar
-for i in ${DIRLIBS}
-do
-  if [ -z "$IREPORT_CLASSPATH" ] ; then
-    IREPORT_CLASSPATH=$i
-  else
-    IREPORT_CLASSPATH="$i":$IREPORT_CLASSPATH
-  fi
-done
-
-DIRLIBS=${EXEDIR}/../lib/*.zip
-for i in ${DIRLIBS}
-do
-  if [ -z "$IREPORT_CLASSPATH" ] ; then
-    IREPORT_CLASSPATH=$i
-  else
-    IREPORT_CLASSPATH="$i":$IREPORT_CLASSPATH
-  fi
-done
-
-IREPORT_CLASSPATH="${EXEDIR}/../classes":"${EXEDIR}/../fonts":$IREPORT_CLASSPATH
-cd ..
-IREPORT_HOME=$(pwd)
-cd bin
-#echo $IREPORT_HOME
+IREPORT_CLASSPATH="%%CLSSPTH%%:%%DATADIR%%/fonts"
+IREPORT_HOME="$HOME/ireport"
 
+# Since iReport-1.2.2, $IREPORT_HOME must be writable
+/bin/mkdir -p $IREPORT_HOME/lib
+/bin/rm $IREPORT_HOME/plugins $IREPORT_HOME/templates 2>/dev/null || /usr/bin/true
+/bin/ln -sf %%DATADIR%%/plugins $IREPORT_HOME/plugins
+/bin/ln -sf %%DATADIR%%/templates $IREPORT_HOME/templates
+cd $IREPORT_HOME
 java -classpath "$IREPORT_CLASSPATH:$CLASSPATH" -Direport.home=$IREPORT_HOME -Djava.security.policy=$IREPORT_HOME/policy.all it.businesslogic.ireport.gui.MainFrame "$@"
