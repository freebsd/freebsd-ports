--- aclocal.m4.orig	2021-06-29 07:24:51 UTC
+++ aclocal.m4
@@ -2221,7 +2221,7 @@ AC_DEFUN([XCODE_VERSION],[
 # FIND_LLVM_PROG()
 # --------------------------------
 # Find where the llvm tools are. We have a special function to handle when they
-# are installed with a version suffix (e.g., llc-7, llc-7.0) and without (e.g.
+# are installed with a version suffix (e.g., llc-7, llc-7.0, llc70) and without (e.g.
 # llc).
 #
 # $1 = the variable to set
@@ -2231,7 +2231,7 @@ AC_DEFUN([FIND_LLVM_PROG],[
 #
 AC_DEFUN([FIND_LLVM_PROG],[
     # Test for program with and without version name.
-    PROG_VERSION_CANDIDATES=$(for llvmVersion in `seq $4 -1 $3`; do echo "$2-$llvmVersion $2-$llvmVersion.0"; done)
+    PROG_VERSION_CANDIDATES=$(for llvmVersion in `seq $4 -1 $3`; do echo "$2-$llvmVersion $2-$llvmVersion.0 $2$llvmVersion $2${llvmVersion}0"; done)
     AC_CHECK_TOOLS([$1], [$PROG_VERSION_CANDIDATES $2], [])
     AS_IF([test x"$$1" != x],[
         PROG_VERSION=`$$1 --version | awk '/.*version [[0-9\.]]+/{for(i=1;i<=NF;i++){ if(\$i ~ /^[[0-9\.]]+$/){print \$i}}}'`
