--- autoheader.sh.orig	Mon Nov 22 21:50:45 1999
+++ autoheader.sh	Mon Nov 22 21:52:02 1999
@@ -194,7 +194,7 @@
   # Some fgrep's have limits on the number of lines that can be in the
   # pattern on the command line, so use a temporary file containing the
   # pattern.
-  (fgrep_tmp=${TMPDIR-/tmp}/autoh$$
+  (fgrep_tmp=`mktemp ${TMPDIR-/tmp}/autoh.XXXXXXXXXX` || exit 1
    trap "rm -f $fgrep_tmp; exit 1" 1 2 15
    cat > $fgrep_tmp <<EOF
 $syms
