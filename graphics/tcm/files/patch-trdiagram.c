--- src/sd/tr/trdiagram.c.orig	Wed Jul 18 00:52:02 2001
+++ src/sd/tr/trdiagram.c	Wed Jul 18 00:52:46 2001
@@ -223,7 +223,7 @@
 void TRDiagram::CheckDocument() {
 	RecalculateTree();
 	chkbuf = "";
-	unsigned total = trChecks->CheckNodeCount(1, MAXINT, Code::TEXT_ROOT, chkbuf);
+	unsigned total = trChecks->CheckNodeCount(1, INT_MAX, Code::TEXT_ROOT, chkbuf);
 	if (total == 0)
 		total += trChecks->CheckReachability(
 			Code::TEXT_ROOT, Code::TEXT_NODE, False, chkbuf);
