--- code/qcommon/vm_x86.c.orig	2016-03-31 19:41:05 UTC
+++ code/qcommon/vm_x86.c
@@ -512,7 +512,7 @@ void VM_Compile( vm_t *vm, vmHeader_t *h
 				break;
 			}
 			if (code[pc+4] == OP_STORE4) {
-				opt = EmitMovEBXEDI(vm, (vm->dataMask & ~3));
+				opt = EmitMovEBXEDI(vm, (vm->dataMask));
 				EmitString( "B8" );			// mov	eax, 0x12345678
 				Emit4( Constant4() );
 //				if (!opt) {
@@ -527,7 +527,7 @@ void VM_Compile( vm_t *vm, vmHeader_t *h
 				break;
 			}
 			if (code[pc+4] == OP_STORE2) {
-				opt = EmitMovEBXEDI(vm, (vm->dataMask & ~1));
+				opt = EmitMovEBXEDI(vm, (vm->dataMask));
 				EmitString( "B8" );			// mov	eax, 0x12345678
 				Emit4( Constant4() );
 //				if (!opt) {
