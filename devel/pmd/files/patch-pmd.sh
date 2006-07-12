$FreeBSD$

. Use /bin/sh rather than /bin/bash
. Use JARs from ${DATADIR}
. Use javavmwrapper

--- bin/pmd.sh.orig	Fri Jan 28 17:13:49 2005
+++ bin/pmd.sh	Tue Jul 11 08:00:10 2006
@@ -1,4 +1,4 @@
-#!/bin/bash
+#!/bin/sh
 
 if [ -z "$3" ]; then
     script=`basename $0`
@@ -7,25 +7,8 @@
     exit 1
 fi
 
-SCRIPT_DIR=`dirname $0`
-CWD="$PWD"
-
-cd "$SCRIPT_DIR/../lib"
-LIB_DIR=`pwd -P`
-
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
 
@@ -38,4 +21,4 @@
 
 # echo "CLASSPATH: $classpath"
 
-java -cp $classpath net.sourceforge.pmd.PMD $FILE $FORMAT $RULESETFILES
+JAVA_VERSION="%%JAVA_VERSION%%" exec "%%LOCALBASE%%/bin/java" -cp $classpath net.sourceforge.pmd.PMD $FILE $FORMAT $RULESETFILES
