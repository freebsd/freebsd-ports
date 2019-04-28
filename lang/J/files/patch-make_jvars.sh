--- make/jvars.sh.orig	2019-03-10 15:55:44 UTC
+++ make/jvars.sh
@@ -2,7 +2,7 @@
 # source shell script (read with . jvars.sh) so stuff is easy to find
 
 # edit following if your install is not standard 
-jgit=~/git/jsource # git jsource folder
+jgit=~/jsource-j807-release # git jsource folder
 jbld=~/jbld        # test libraries and binaries will be put here
 
 # platform and shared library suffix
@@ -10,7 +10,12 @@ jplatform=`uname|tr '[:upper:]' '[:lower:]'`
 jsuffix=so
 if [ $jplatform = "darwin" ] ; then jsuffix=dylib ; fi
 
-CC=clang # compiler
+USE_OPENMP="${USE_OPENMP:=0}"
+if [ $USE_OPENMP -eq 1 ] ; then
+    CC=gcc8
+else
+    CC=clang # compiler
+fi
 
 # should not be necessary to edit after here
 tsu=$jgit/test/tsu.ijs
