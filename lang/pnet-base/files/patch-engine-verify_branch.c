--- engine/verify_branch.c.orig	Fri May 28 21:02:51 2004
+++ engine/verify_branch.c	Thu Jun  3 13:36:28 2004
@@ -218,7 +218,7 @@
 			stack[posn].engineType == ILEngineType_I)
 		{
 			if(labelStack[posn].engineType == ILEngineType_I8 ||
-				labelStack[posn].engineType = ILEngineType_I)
+				labelStack[posn].engineType == ILEngineType_I)
 			{
 				continue;
 			}
