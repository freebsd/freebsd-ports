$FreeBSD$

. Use JARs from ${DATADIR}
. Use javavmwrapper

--- bin/cpd.sh.orig	Mon Apr 17 23:28:11 2006
+++ bin/cpd.sh	Tue Jul 11 07:47:13 2006
@@ -20,26 +20,8 @@
 				exit 1
 fi
 
-
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
-				cd "$build_dir"
-				build_dir=`pwd -P`
-				classpath=$classpath:$build_dir
-fi
-
-cd "$CWD"
-
-for jarfile in `ls $LIB_DIR/*.jar`; do
+for jarfile in `ls %%DATADIR%%/*.jar`; do
 				classpath=$classpath:$jarfile
 done
 
@@ -62,4 +44,4 @@
 
 # echo "CLASSPATH: $classpath"
 
-java $HEAPSIZE -cp $classpath net.sourceforge.pmd.cpd.CPD --minimum-tokens $MINIMUM_TOKENS --files $DIRECTORY --language $LANGUAGE
+JAVA_VERSION="%%JAVA_VERSION%%" exec "%%LOCALBASE%%/bin/java" $HEAPSIZE -cp $classpath net.sourceforge.pmd.cpd.CPD --minimum-tokens $MINIMUM_TOKENS --files $DIRECTORY --language $LANGUAGE
