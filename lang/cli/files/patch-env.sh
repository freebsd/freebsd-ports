
$FreeBSD$

--- env.sh.orig	Fri Mar 22 03:47:54 2002
+++ env.sh	Tue Apr 16 18:38:49 2002
@@ -69,7 +69,15 @@
 export DEBUGGING_SUPPORTED_BUILD=1
 export SVR_WKS_DIRS=wks
 
-if test X"$1" = "Xfree"
+if test X"$1" = "Xretail"
+then
+echo "Retail Environment"
+export DDKBUILDENV=free
+export C_DEFINES="${C_DEFINES} -DNTMAKEENV -DNDEBUG -DPERF_TRACKING"
+export BUILD_ALT_DIR=r
+export TARGETCOMPLUS="${ROTOR_DIR}/build/v1.x86fre.rotor"
+export NTDEBUG=retail
+else if test X"$1" = "Xfree"
 then
 echo "Free Environment"
 export DDKBUILDENV=free
@@ -93,6 +101,7 @@
 export BUILD_ALT_DIR=df
 export TARGETCOMPLUS="${ROTOR_DIR}/build/v1.x86fstchk.rotor"
 export NTDEBUG=ntsd
+fi
 fi
 fi
  
