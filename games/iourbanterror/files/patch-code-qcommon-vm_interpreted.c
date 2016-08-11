--- code/qcommon/vm_interpreted.c.orig	2016-03-31 19:41:05 UTC
+++ code/qcommon/vm_interpreted.c
@@ -458,11 +458,11 @@ nextInstruction2:
 			goto nextInstruction2;
 
 		case OP_STORE4:
-			*(int *)&image[ r1&(dataMask & ~3) ] = r0;
+			*(int *)&image[ r1&(dataMask) ] = r0;
 			opStack -= 2;
 			goto nextInstruction;
 		case OP_STORE2:
-			*(short *)&image[ r1&(dataMask & ~1) ] = r0;
+			*(short *)&image[ r1&(dataMask) ] = r0;
 			opStack -= 2;
 			goto nextInstruction;
 		case OP_STORE1:
