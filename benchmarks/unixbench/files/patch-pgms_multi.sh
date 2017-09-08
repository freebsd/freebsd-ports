--- pgms/multi.sh.orig	2015-06-04 17:20:18 UTC
+++ pgms/multi.sh
@@ -14,6 +14,7 @@
 #
 ###############################################################################
 ID="@(#)multi.sh:3.4 -- 5/15/91 19:30:24";
+cd ${TMPDIR}
 instance=1
 while [ $instance -le $1 ]; do
 	/bin/sh "$UB_BINDIR/tst.sh" &
