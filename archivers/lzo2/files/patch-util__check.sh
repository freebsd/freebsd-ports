--- ./util/check.sh.orig	2011-04-23 12:55:35.000000000 +0200
+++ ./util/check.sh	2011-05-10 21:45:44.000000000 +0200
@@ -19,7 +19,7 @@
 
 TMPFILE="/tmp/lzo_$$.tmp"
 rm -f $TMPFILE
-(find $dir/ -type f -print > $TMPFILE) || true
+find $dir/ -type f -print | tee $TMPFILE
 
 ## methods=`$LZOTEST -m | sed -n 's/^ *-m\([0-9]*\).*/\1/p'`
 ## methods="9721 9722 9723 9724 9725 9726 9727 9728 9729"
