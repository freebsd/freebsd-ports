diff -r de1eebcbab05 code/qcommon/vm_interpreted.c
--- code/qcommon/vm_interpreted.c	Mon Jul 15 20:43:44 2013 +0200
+++ code/qcommon/vm_interpreted.c	Tue Jul 23 10:41:47 2013 +0200
@@ -436,21 +436,21 @@
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
@@ -460,7 +460,7 @@
 
 		case OP_ARG:
 			// single byte offset from programStack
-			*(int *)&image[ (codeImage[programCounter] + programStack)&dataMask&~3 ] = r0;
+			*(int *)&image[ (codeImage[programCounter] + programStack)&dataMask ] = r0;
 			opStackOfs--;
 			programCounter += 1;
 			goto nextInstruction;
a05650c847d3648d03593516ce310db4
echo x - games/iourbanterror/files/patch-code-qcommon-vm_x86.c
sed 's/^X//' >games/iourbanterror/files/patch-code-qcommon-vm_x86.c << 'b99229479f1b9014d0f8028a3c1f2c41'
diff -r de1eebcbab05 code/qcommon/vm_x86.c
--- code/qcommon/vm_x86.c	Mon Jul 15 20:43:44 2013 +0200
+++ code/qcommon/vm_x86.c	Tue Jul 23 10:41:43 2013 +0200
@@ -783,7 +783,7 @@
 		return qtrue;
 
 	case OP_STORE4:
-		EmitMovEAXStack(vm, (vm->dataMask & ~3));
+		EmitMovEAXStack(vm, vm->dataMask);
 #if idx64
 		EmitRexString(0x41, "C7 04 01");		// mov dword ptr [r9 + eax], 0x12345678
 		Emit4(Constant4());
@@ -798,7 +798,7 @@
 		return qtrue;
 
 	case OP_STORE2:
-		EmitMovEAXStack(vm, (vm->dataMask & ~1));
+		EmitMovEAXStack(vm, vm->dataMask);
 #if idx64
 		Emit1(0x66);					// mov word ptr [r9 + eax], 0x1234
 		EmitRexString(0x41, "C7 04 01");
@@ -1369,7 +1369,7 @@
 		case OP_STORE4:
 			EmitMovEAXStack(vm, 0);	
 			EmitString("8B 54 9F FC");			// mov edx, dword ptr -4[edi + ebx * 4]
-			MASK_REG("E2", vm->dataMask & ~3);		// and edx, 0x12345678
+			MASK_REG("E2", vm->dataMask);			// and edx, 0x12345678
 #if idx64
 			EmitRexString(0x41, "89 04 11");		// mov dword ptr [r9 + edx], eax
 #else
@@ -1381,7 +1381,7 @@
 		case OP_STORE2:
 			EmitMovEAXStack(vm, 0);	
 			EmitString("8B 54 9F FC");			// mov edx, dword ptr -4[edi + ebx * 4]
-			MASK_REG("E2", vm->dataMask & ~1);		// and edx, 0x12345678
+			MASK_REG("E2", vm->dataMask);			// and edx, 0x12345678
 #if idx64
 			Emit1(0x66);					// mov word ptr [r9 + edx], eax
 			EmitRexString(0x41, "89 04 11");
b99229479f1b9014d0f8028a3c1f2c41
exit
