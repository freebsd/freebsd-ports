--- test/kapp/run-sig-core.sh.orig	2017-10-27 07:23:08 UTC
+++ test/kapp/run-sig-core.sh
@@ -29,12 +29,12 @@ BUILD_TYPE="$3"
 
 SIGQUIT=3
 
-function killFromBackground ()
+killFromBackground ()
 {
     PARENT_PID=$1
     for I in 1 2 3 4 5
     do
-        COMMAND="ps -ef|awk '\$3==${PARENT_PID} && \$8==\"${BINARY_PATH}\"  {print \$2}'"
+        COMMAND="ps awwo pid,ppid,command|awk '\$2==${PARENT_PID} && \$3==\"${BINARY_PATH}\"  {print \$1}'"
         eval PID=\`${COMMAND}\`
         if [ "$PID" = "" ]; then
             sleep 1
@@ -44,7 +44,7 @@ function killFromBackground ()
     done
 
     if [ "$PID" != "" ]; then
-        kill -s $SIGQUIT $PID
+        kill -s QUIT $PID
     fi
 
     echo $PID > killed.pid
@@ -63,6 +63,13 @@ if [ "$HOST_OS" = "mac" ]; then
    fi
 
    CORE_FOLDER="/core/"
+elif [ "$HOST_OS" = "bsd" ]; then
+   if [ "`ulimit -c`" = "0" ] || [ "`/sbin/sysctl -n kern.coredump`" != "1" ]; then
+       echo "Core files are disabled. Skipping core file tests"
+       exit 0
+   fi
+
+   CORE_FOLDER="./"
 elif [ "$HOST_OS" = "linux" ]; then
    if [ "`ulimit -c`" = "0" ]; then
        echo "Core files are disabled. Skipping core file tests"
@@ -92,7 +99,7 @@ wait
 BINARY_PID=`cat killed.pid`
 rm killed.pid
 
-CORE_FILE="${CORE_FOLDER}core.${BINARY_PID}"
+CORE_FILE="${CORE_FOLDER}${BINARY_PATH##*/}.core"
 
 if [ "$BUILD_TYPE" = "dbg" ]; then
    if [ -f $CORE_FILE ]; then
