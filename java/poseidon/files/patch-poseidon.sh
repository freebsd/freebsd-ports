--- bin/poseidon.sh.orig	Wed Mar 10 12:58:56 2004
+++ bin/poseidon.sh	Fri Apr  9 00:12:53 2004
@@ -1,4 +1,7 @@
-#!/bin/bash
+#!/bin/sh
+
+JAVA_HOME=%%JAVA_HOME%%
+POSEIDONCE_HOME=$HOME/.poseidonCE
 
 RealPath() {
 	cmd=`basename $0`
@@ -10,9 +13,9 @@
 
         	cd `dirname $link`
 	done
-								        
+
 	echo `pwd -P`/$cmd
-}										
+}
 
 if [ -z "$JAVA_HOME" ] ; then
     echo "Could not find a JDK."
@@ -38,5 +41,5 @@
 
 export CLASSPATH
 
-"$JAVACMD" -Xms64m -Xmx160m -Dposeidon.java.home="$JAVA_HOME" -Dposeidon.user.dir.PE="$POSEIDONPE_HOME" com.gentleware.poseidon.Poseidon $project
+"$JAVACMD" -Xms64m -Xmx160m -Dposeidon.java.home="$JAVA_HOME" -Dposeidon.user.dir.CE="$POSEIDONCE_HOME" com.gentleware.poseidon.Poseidon $project
 
