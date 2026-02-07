--- pgms/tst.sh.orig	2015-06-04 17:20:18 UTC
+++ pgms/tst.sh
@@ -14,7 +14,7 @@
 #
 ###############################################################################
 ID="@(#)tst.sh:3.4 -- 5/15/91 19:30:24";
-sort >sort.$$ <sort.src
+sort >sort.$$ < ${UB_TESTDIR}/sort.src
 od sort.$$ | sort -n -k 1 > od.$$
 grep the sort.$$ | tee grep.$$ | wc > wc.$$
 rm sort.$$ grep.$$ od.$$ wc.$$
