$FreeBSD$

. Use /bin/sh rather than /bin/bash
. Use JARs from ${DATADIR}
. Use javavmwrapper

--- bin/designer.sh.orig	Fri Jan 28 17:13:49 2005
+++ bin/designer.sh	Tue Jul 11 08:00:06 2006
@@ -1,24 +1,7 @@
-#!/bin/bash
-
-SCRIPT_DIR=`dirname $0`
-CWD="$PWD"
-
-cd "$SCRIPT_DIR/../lib"
-LIB_DIR=`pwd -P`
+#!/bin/sh
 
 classpath=$CLASSPATH
-
-build_dir="$SCRIPT_DIR/../build"
-
-if [ -d "$build_dir" ]; then
-    cd "$build_dir"
-    build_dir=`pwd -P`
-    classpath=$classpath:$build_dir
-fi
-
-cd "$CWD"
-
-for jarfile in `ls $LIB_DIR/*.jar`; do
+for jarfile in `ls %%DATADIR%%/*.jar`; do
     classpath=$classpath:$jarfile
 done
 
@@ -31,4 +14,4 @@
 
 # echo "CLASSPATH: $classpath"
 
-java -cp $classpath net.sourceforge.pmd.util.designer.Designer
+JAVA_VERSION="%%JAVA_VERSION%%" exec "%%LOCALBASE%%/bin/java" -cp $classpath net.sourceforge.pmd.util.designer.Designer
