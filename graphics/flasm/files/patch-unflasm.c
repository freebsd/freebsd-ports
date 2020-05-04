--- unflasm.c.orig	2020-05-02 15:54:36 UTC
+++ unflasm.c
@@ -29,7 +29,7 @@ static int targetIndent = 0;
 static long int swfabspos = -1;
 static long int swfrelpos = -1;
 
-int swfVersion;
+extern int swfVersion;
 
 static int showLiterals;
 static int nDict = 0;
@@ -1012,29 +1012,11 @@ static void printActionRecord(byte *p, Action type, un
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
