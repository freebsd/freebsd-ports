--- pgms/multi.sh.orig	1995-11-28 00:19:10 UTC
+++ pgms/multi.sh
@@ -14,6 +14,7 @@
 #
 ###############################################################################
 ID="@(#)multi.sh:3.4 -- 5/15/91 19:30:24";
+cd ${TMPDIR}
 instance=1
 while [ $instance -le $1 ]; do
 	/bin/sh $BINDIR/tst.sh &
