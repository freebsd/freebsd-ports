$FreeBSD$

. Use JARs from ${DATADIR}
. Use javavmwrapper

--- bin/bgastviewer.sh.orig	Fri May 26 05:37:58 2006
+++ bin/bgastviewer.sh	Fri Jul  7 21:46:32 2006
@@ -1 +1,9 @@
-java -cp ../build:../lib/jakarta-oro-2.0.8.jar:../lib/pmd-3.7.jar:../lib/xercesImpl-2.6.2.jar:../lib/xmlParserAPIs-2.6.2.jar:../lib/jaxen-1.1-beta-7.jar net.sourceforge.pmd.util.viewer.Viewer
+#!/bin/sh
+
+JARS=`/bin/ls -1 %%DATADIR%%/*jar`
+CLASSPATH=""
+for jar in $JARS; do
+  CLASSPATH="$CLASSPATH:$jar"
+done
+
+JAVA_VERSION="%%JAVA_VERSION%%" exec "%%LOCALBASE%%/bin/java" -cp $CLASSPATH net.sourceforge.pmd.util.viewer.Viewer
