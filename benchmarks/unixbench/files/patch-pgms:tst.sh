--- pgms/tst.sh.orig	Sun Dec 19 01:41:24 2004
+++ pgms/tst.sh	Sun Dec 19 01:41:49 2004
@@ -14,7 +14,7 @@
 #
 ###############################################################################
 ID="@(#)tst.sh:3.4 -- 5/15/91 19:30:24";
-sort >sort.$$ <sort.src
+sort >sort.$$ < ${TESTDIR}/sort.src
 od sort.$$ | sort -n +1 > od.$$
 grep the sort.$$ | tee grep.$$ | wc > wc.$$
 rm sort.$$ grep.$$ od.$$ wc.$$
