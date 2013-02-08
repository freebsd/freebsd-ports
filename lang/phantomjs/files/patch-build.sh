$FreeBSD$

--- build.sh.orig	2013-01-15 07:48:35.556438142 +0900
+++ build.sh	2013-01-15 07:50:27.581439602 +0900
@@ -8,27 +8,27 @@
 COMPILE_JOBS=1
 MAKEFLAGS_JOBS=''
 
-if [[ "$MAKEFLAGS" != "" ]]; then
-  MAKEFLAGS_JOBS=$(echo $MAKEFLAGS | egrep -o '\-j[0-9]+' | egrep -o '[0-9]+')
-fi
-
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
+#if [[ "$MAKEFLAGS" != "" ]]; then
+#  MAKEFLAGS_JOBS=$(echo $MAKEFLAGS | egrep -o '\-j[0-9]+' | egrep -o '[0-9]+')
+#fi
+
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
@@ -78,10 +78,10 @@
 EOF
 
     echo "Do you want to continue (y/n)?"
-    read continue
-    if [[ "$continue" != "y" ]]; then
-        exit 1
-    fi
+#    read continue
+#    if [[ "$continue" != "y" ]]; then
+#        exit 1
+#    fi
     echo
     echo
 fi
