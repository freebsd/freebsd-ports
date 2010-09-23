
$FreeBSD$

--- tests/subr.sh.orig
+++ tests/subr.sh
@@ -29,7 +29,7 @@
 SBCL_HOME="$SBCL_PWD/../contrib"
 SBCL_CORE="$SBCL_PWD/../output/sbcl.core"
 SBCL_RUNTIME="$SBCL_PWD/../src/runtime/sbcl"
-SBCL_ARGS="--noinform --no-sysinit --no-userinit --noprint --disable-debugger"
+SBCL_ARGS="${LISP_EXTRA_ARG} --noinform --no-sysinit --no-userinit --noprint --disable-debugger"
 
 # Scripts that use these variables should quote them.
 TEST_BASENAME="$(basename $0)"
