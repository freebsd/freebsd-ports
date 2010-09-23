
$FreeBSD$

--- doc/manual/make-tempfiles.sh.orig
+++ doc/manual/make-tempfiles.sh
@@ -33,7 +33,7 @@
     SBCLRUNTIME="$1"
 fi
 
-SBCL="$SBCLRUNTIME --noinform --no-sysinit --no-userinit --noprint --disable-debugger"
+SBCL="$SBCLRUNTIME ${LISP_EXTRA_ARG} --noinform --no-sysinit --no-userinit --noprint --disable-debugger"
 
 # extract version and date
 VERSION=`$SBCL --eval '(write-line (lisp-implementation-version))' --eval '(sb-ext:quit)'`
