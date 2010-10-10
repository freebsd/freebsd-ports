--- unflasm.c.orig	2007-06-10 03:40:47.000000000 +0900
+++ unflasm.c	2010-07-22 12:09:29.000000000 +0900
@@ -1012,29 +1012,11 @@
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
