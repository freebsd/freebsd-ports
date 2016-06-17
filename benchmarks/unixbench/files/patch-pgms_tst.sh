--- pgms/tst.sh.orig	1995-11-27 17:07:03 UTC
+++ pgms/tst.sh
@@ -14,7 +14,7 @@
 #
 ###############################################################################
 ID="@(#)tst.sh:3.4 -- 5/15/91 19:30:24";
-sort >sort.$$ <sort.src
+sort >sort.$$ < ${TESTDIR}/sort.src
 od sort.$$ | sort -n +1 > od.$$
 grep the sort.$$ | tee grep.$$ | wc > wc.$$
 rm sort.$$ grep.$$ od.$$ wc.$$
