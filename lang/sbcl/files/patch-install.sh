
$FreeBSD$

--- install.sh.orig
+++ install.sh
@@ -72,7 +72,7 @@
 . ./sbcl-pwd.sh
 sbcl_pwd
 
-SBCL="$SBCL_PWD/src/runtime/sbcl --noinform --core $SBCL_PWD/output/sbcl.core --no-userinit --no-sysinit --disable-debugger"
+SBCL="$SBCL_PWD/src/runtime/sbcl ${LISP_EXTRA_ARG} --noinform --core $SBCL_PWD/output/sbcl.core --no-userinit --no-sysinit --disable-debugger"
 SBCL_BUILDING_CONTRIB=1
 export SBCL SBCL_BUILDING_CONTRIB
 
