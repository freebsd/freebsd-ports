--- src/sd/bv/atdiagram.c.orig	Wed Jul 18 01:50:27 2001
+++ src/sd/bv/atdiagram.c	Wed Jul 18 01:50:46 2001
@@ -314,14 +314,14 @@
 	errors += atChecks->CheckNodeCount(1, Code::ATD_FINAL_STATE_NODE, chkbuf);
 	if (errors == 0)    // only useful with 1 INITIAL && 1 FINAL state
 		errors += atChecks->CheckUnreachableStates(chkbuf);
-	errors += atChecks->CheckNodeCount(1, MAXINT, Code::ATD_ACTION_STATE_NODE, chkbuf);
+	errors += atChecks->CheckNodeCount(1, INT_MAX, Code::ATD_ACTION_STATE_NODE, chkbuf);
 
 	errors += atChecks->CheckNamelessNodes(Code::ATD_ACTION_STATE_NODE, chkbuf);
 	errors += atChecks->CheckNamelessNodes(Code::ATD_WAIT_STATE_NODE, chkbuf);
 
 
 	errors += atChecks->CheckCountEdgesFrom(Code::ATD_SYNCHRONIZATION_NODE, 
-		Code::ATD_TRANSITION_EDGE, 2, MAXINT, False, False, chkbuf);
+		Code::ATD_TRANSITION_EDGE, 2, INT_MAX, False, False, chkbuf);
 
 	ReportCheck(errors, &chkbuf);
 }
