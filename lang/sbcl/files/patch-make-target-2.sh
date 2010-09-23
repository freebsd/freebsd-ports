
$FreeBSD$

--- make-target-2.sh.orig
+++ make-target-2.sh
@@ -31,11 +31,13 @@
 # for much longer than that, don't worry, it's likely to be normal.
 echo //doing warm init - compilation phase
 ./src/runtime/sbcl \
+${LISP_EXTRA_ARG} \
 --core output/cold-sbcl.core \
 --lose-on-corruption \
 --no-sysinit --no-userinit < make-target-2.lisp
 echo //doing warm init - load and dump phase
 ./src/runtime/sbcl \
+${LISP_EXTRA_ARG} \
 --core output/cold-sbcl.core \
 --lose-on-corruption \
 --no-sysinit --no-userinit < make-target-2-load.lisp
