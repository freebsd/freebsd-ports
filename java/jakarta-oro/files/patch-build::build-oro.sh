$FreeBSD$

--- build/build-oro.sh.orig	Fri Dec  8 15:59:15 2000
+++ build/build-oro.sh	Fri Dec  8 15:59:29 2000
@@ -36,7 +36,7 @@
 
 echo "Now building ${TARGET}..."
 
-CP=${CLASSPATH}:ant.jar:xml.jar
+CP=ant.jar:xml.jar:${CLASSPATH}
 
 echo "Classpath: ${CP}"
 echo "JAVA_HOME: ${JAVA_HOME}"
