
$FreeBSD$

--- env.sh.orig	Fri Mar 22 03:47:54 2002
+++ env.sh	Fri Mar 29 20:01:48 2002
@@ -69,14 +69,14 @@
 export DEBUGGING_SUPPORTED_BUILD=1
 export SVR_WKS_DIRS=wks
 
-if test X"$1" = "Xfree"
+if true
 then
 echo "Free Environment"
 export DDKBUILDENV=free
 export C_DEFINES="${C_DEFINES} -DNTMAKEENV -DNDEBUG -DPERF_TRACKING"
 export BUILD_ALT_DIR=r
 export TARGETCOMPLUS="${ROTOR_DIR}/build/v1.x86fre.rotor"
-export NTDEBUG=ntsdnodbg
+export NTDEBUG=retail
 else if test X"$1" = "Xchecked"
 then
 echo "Checked Environment"
@@ -104,3 +104,5 @@
 export PATH=${PATH}:${TARGETCOMPLUS}/int_tools
 export LD_LIBRARY_PATH="${TARGETCOMPLUS}"
 export LD_LIB_DIRS="-L${TARGETCOMPLUS}"
+
+exec "$@"
