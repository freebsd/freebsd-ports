--- code/qcommon/vm_interpreted.c.orig	2013-07-15 18:54:41.000000000 +0000
+++ code/qcommon/vm_interpreted.c
@@ -436,21 +436,21 @@ nextInstruction2:
 				return 0;
 			}
 #endif
-			r0 = opStack[opStackOfs] = *(int *) &image[r0 & dataMask & ~3 ];
+			r0 = opStack[opStackOfs] = *(int *) &image[r0 & dataMask ];
 			goto nextInstruction2;
 		case OP_LOAD2:
-			r0 = opStack[opStackOfs] = *(unsigned short *)&image[ r0&dataMask&~1 ];
+			r0 = opStack[opStackOfs] = *(unsigned short *)&image[ r0&dataMask ];
 			goto nextInstruction2;
 		case OP_LOAD1:
 			r0 = opStack[opStackOfs] = image[ r0&dataMask ];
 			goto nextInstruction2;
 
 		case OP_STORE4:
-			*(int *)&image[ r1&(dataMask & ~3) ] = r0;
+			*(int *)&image[ r1&dataMask ] = r0;
 			opStackOfs -= 2;
 			goto nextInstruction;
 		case OP_STORE2:
-			*(short *)&image[ r1&(dataMask & ~1) ] = r0;
+			*(short *)&image[ r1&dataMask ] = r0;
 			opStackOfs -= 2;
 			goto nextInstruction;
 		case OP_STORE1:
@@ -460,7 +460,7 @@ nextInstruction2:
 
 		case OP_ARG:
 			// single byte offset from programStack
-			*(int *)&image[ (codeImage[programCounter] + programStack)&dataMask&~3 ] = r0;
+			*(int *)&image[ (codeImage[programCounter] + programStack)&dataMask ] = r0;
 			opStackOfs--;
 			programCounter += 1;
 			goto nextInstruction;
