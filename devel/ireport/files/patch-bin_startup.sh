--- bin/startup.sh.orig	Wed Apr 26 07:35:37 2006
+++ bin/startup.sh	Sat Apr 29 00:04:02 2006
@@ -1,30 +1,12 @@
 #! /bin/sh
 
+IREPORT_CLASSPATH="%%CLSSPTH%%:%%DATADIR%%/fonts"
+IREPORT_HOME="$HOME/ireport"
 
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
-IREPORT_HOME="${EXEDIR}/.."
-
+# Since iReport-1.2.2, $IREPORT_HOME must be writable
+/bin/mkdir -p $IREPORT_HOME/lib
+/bin/rm $IREPORT_HOME/plugins $IREPORT_HOME/templates 2>/dev/null || /usr/bin/true
+/bin/ln -sf %%DATADIR%%/plugins $IREPORT_HOME/plugins
+/bin/ln -sf %%DATADIR%%/templates $IREPORT_HOME/templates
+cd $IREPORT_HOME
 java -classpath "$IREPORT_CLASSPATH:$CLASSPATH" -Direport.home=$IREPORT_HOME it.businesslogic.ireport.gui.MainFrame "$@"
