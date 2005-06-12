--- bin/startup.sh.orig	Fri Jan 28 02:01:47 2005
+++ bin/startup.sh	Mon May 23 21:45:26 2005
@@ -1,30 +1,6 @@
 #! /bin/sh
 
-
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
-IREPORT_CLASSPATH="${EXEDIR}/../classes":$IREPORT_CLASSPATH
-IREPORT_HOME="${EXEDIR}/.."
+IREPORT_CLASSPATH="%%CLSSPTH%%"
+IREPORT_HOME="%%DATADIR%%"
 
 java -classpath "$IREPORT_CLASSPATH:$CLASSPATH" -Direport.home=$IREPORT_HOME it.businesslogic.ireport.gui.MainFrame "$@"
