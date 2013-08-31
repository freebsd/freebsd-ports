--- code/qcommon/vm_x86.c.orig	2013-07-15 18:54:41.000000000 +0000
+++ code/qcommon/vm_x86.c
@@ -783,7 +783,7 @@ qboolean ConstOptimize(vm_t *vm, int cal
 		return qtrue;
 
 	case OP_STORE4:
-		EmitMovEAXStack(vm, (vm->dataMask & ~3));
+		EmitMovEAXStack(vm, vm->dataMask);
 #if idx64
 		EmitRexString(0x41, "C7 04 01");		// mov dword ptr [r9 + eax], 0x12345678
 		Emit4(Constant4());
@@ -798,7 +798,7 @@ qboolean ConstOptimize(vm_t *vm, int cal
 		return qtrue;
 
 	case OP_STORE2:
-		EmitMovEAXStack(vm, (vm->dataMask & ~1));
+		EmitMovEAXStack(vm, vm->dataMask);
 #if idx64
 		Emit1(0x66);					// mov word ptr [r9 + eax], 0x1234
 		EmitRexString(0x41, "C7 04 01");
@@ -1369,7 +1369,7 @@ void VM_Compile(vm_t *vm, vmHeader_t *he
 		case OP_STORE4:
 			EmitMovEAXStack(vm, 0);	
 			EmitString("8B 54 9F FC");			// mov edx, dword ptr -4[edi + ebx * 4]
-			MASK_REG("E2", vm->dataMask & ~3);		// and edx, 0x12345678
+			MASK_REG("E2", vm->dataMask);			// and edx, 0x12345678
 #if idx64
 			EmitRexString(0x41, "89 04 11");		// mov dword ptr [r9 + edx], eax
 #else
@@ -1381,7 +1381,7 @@ void VM_Compile(vm_t *vm, vmHeader_t *he
 		case OP_STORE2:
 			EmitMovEAXStack(vm, 0);	
 			EmitString("8B 54 9F FC");			// mov edx, dword ptr -4[edi + ebx * 4]
-			MASK_REG("E2", vm->dataMask & ~1);		// and edx, 0x12345678
+			MASK_REG("E2", vm->dataMask);			// and edx, 0x12345678
 #if idx64
 			Emit1(0x66);					// mov word ptr [r9 + edx], eax
 			EmitRexString(0x41, "89 04 11");
