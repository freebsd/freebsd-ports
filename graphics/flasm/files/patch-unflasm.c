--- ./unflasm.c.orig	2014-03-18 08:44:06.055828097 +0100
+++ ./unflasm.c	2014-03-18 08:44:06.060828422 +0100
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
