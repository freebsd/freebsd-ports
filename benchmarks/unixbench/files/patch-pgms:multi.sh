--- pgms/multi.sh.orig	Sun Dec 19 01:44:14 2004
+++ pgms/multi.sh	Sun Dec 19 01:44:24 2004
@@ -14,6 +14,7 @@
 #
 ###############################################################################
 ID="@(#)multi.sh:3.4 -- 5/15/91 19:30:24";
+cd ${TMPDIR}
 instance=1
 while [ $instance -le $1 ]; do
 	/bin/sh $BINDIR/tst.sh &
