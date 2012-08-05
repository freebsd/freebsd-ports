$FreeBSD$

--- build.sh.orig	2012-07-30 01:56:37.113285721 +0900
+++ build.sh	2012-07-30 06:42:31.502288222 +0900
@@ -7,27 +7,27 @@
 COMPILE_JOBS=1
 MAKEFLAGS_JOBS=''
 
-if [[ "$MAKEFLAGS" != "" ]]; then
-  MAKEFLAGS_JOBS=$(echo $MAKEFLAGS | egrep -o '\-j[0-9]+' | egrep -o '[0-9]+')
-fi
+#if [[ "$MAKEFLAGS" != "" ]]; then
+#  MAKEFLAGS_JOBS=$(echo $MAKEFLAGS | egrep -o '\-j[0-9]+' | egrep -o '[0-9]+')
+#fi
 
-if [[ "$MAKEFLAGS_JOBS" != "" ]]; then
-  # user defined number of jobs in MAKEFLAGS, re-use that number
-  COMPILE_JOBS=$MAKEFLAGS_JOBS
-elif [[ $OSTYPE = darwin* ]]; then
-   # We only support modern Mac machines, they are at least using
-   # hyperthreaded dual-core CPU.
-   COMPILE_JOBS=4
-else
-   CPU_CORES=`grep -c ^processor /proc/cpuinfo`
-   if [[ "$CPU_CORES" -gt 1 ]]; then
-       COMPILE_JOBS=$CPU_CORES
-       if [[ "$COMPILE_JOBS" -gt 8 ]]; then
-           # Safety net.
-           COMPILE_JOBS=8
-       fi
-   fi
-fi
+#if [[ "$MAKEFLAGS_JOBS" != "" ]]; then
+#  # user defined number of jobs in MAKEFLAGS, re-use that number
+#  COMPILE_JOBS=$MAKEFLAGS_JOBS
+#elif [[ $OSTYPE = darwin* ]]; then
+#   # We only support modern Mac machines, they are at least using
+#   # hyperthreaded dual-core CPU.
+#   COMPILE_JOBS=4
+#else
+#   CPU_CORES=`grep -c ^processor /proc/cpuinfo`
+#   if [[ "$CPU_CORES" -gt 1 ]]; then
+#       COMPILE_JOBS=$CPU_CORES
+#       if [[ "$COMPILE_JOBS" -gt 8 ]]; then
+#           # Safety net.
+#           COMPILE_JOBS=8
+#       fi
+#   fi
+#fi
 
 until [ -z "$1" ]; do
     case $1 in
