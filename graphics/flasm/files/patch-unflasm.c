--- unflasm.c.orig	Tue Jun  1 23:05:40 2004
+++ unflasm.c	Tue Jun  1 23:07:05 2004
@@ -991,29 +991,11 @@
 			}
 
 		case SWFACTION_SETTARGET:
-			{
-				if (targetIndent == 1) {
-					--indent;
-					print("end\n");
-					targetIndent = 0;
-				}
-				if (strlen((char *) p) > 0) {
-					print("setTarget '%s'\n", p);
-					++indent;
-					targetIndent = 1;
-				}
-				break;
-			}
+			print("setTarget '%s'\n", p);
+			break;
 
 		case SWFACTION_SETTARGETEXPRESSION:
-			if (targetIndent == 1) {
-				--indent;
-				print("end\n");
-				targetIndent = 0;
-			}
 			print("setTargetExpr\n");
-			++indent;
-			targetIndent = 1;
 			break;
 
 		case SWFACTION_GOTOLABEL:
