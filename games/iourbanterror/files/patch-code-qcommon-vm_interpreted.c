--- code/qcommon/vm_interpreted.c.orig	2014-03-23 17:14:22.000000000 +0100
+++ code/qcommon/vm_interpreted.c	2014-03-23 17:17:07.000000000 +0100
@@ -458,11 +458,11 @@
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
