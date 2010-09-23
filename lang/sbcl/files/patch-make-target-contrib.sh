
$FreeBSD$

--- make-target-contrib.sh.orig
+++ make-target-contrib.sh
@@ -32,7 +32,7 @@
     SBCL_PWD=`echo $SBCL_PWD | sed s/\ /\\\\\\\\\ /g`
 fi
 
-SBCL="$SBCL_PWD/src/runtime/sbcl --noinform --core $SBCL_PWD/output/sbcl.core \
+SBCL="$SBCL_PWD/src/runtime/sbcl ${LISP_EXTRA_ARG} --noinform --core $SBCL_PWD/output/sbcl.core \
 --lose-on-corruption --disable-debugger --no-sysinit --no-userinit"
 SBCL_BUILDING_CONTRIB=1
 export SBCL SBCL_BUILDING_CONTRIB
