
$FreeBSD$

--- env.sh.orig	Sat Nov  2 04:21:57 2002
+++ env.sh	Fri Apr 25 10:16:50 2003
@@ -188,7 +188,15 @@
     CSC_COMPILE_FLAGS="${CSC_COMPILE_FLAGS} /d:FEATURE_CASE_SENSITIVE_FILESYSTEM"
 fi
 
-if test X"$1" = "Xfree"
+if test X"$1" = "Xretail"
+then
+echo "Retail Environment"
+    DDKBUILDENV=free
+    C_DEFINES="${C_DEFINES} -DNTMAKEENV -DNDEBUG -DPERF_TRACKING"
+    BUILD_ALT_DIR=r
+    TARGETCOMPLUS="${ROTOR_DIR}/build/v1.x86fre.rotor"
+    NTDEBUG=retail
+else if test X"$1" = "Xfree"
 then
     echo "Free Environment"
     DDKBUILDENV=free
@@ -213,6 +221,7 @@
     BUILD_ALT_DIR=df
     TARGETCOMPLUS="${ROTOR_DIR}/build/v1.${PROCESSOR_ARCHITECTURE}fstchk.rotor"
     NTDEBUG=ntsd
+fi
 fi
 fi
  
