--- code/qcommon/vm_x86.c.orig	2014-03-23 17:23:18.000000000 +0100
+++ code/qcommon/vm_x86.c	2014-03-23 17:24:58.000000000 +0100
@@ -512,7 +512,7 @@
 				break;
 			}
 			if (code[pc+4] == OP_STORE4) {
-				opt = EmitMovEBXEDI(vm, (vm->dataMask & ~3));
+				opt = EmitMovEBXEDI(vm, (vm->dataMask));
 				EmitString( "B8" );			// mov	eax, 0x12345678
 				Emit4( Constant4() );
 //				if (!opt) {
@@ -527,7 +527,7 @@
 				break;
 			}
 			if (code[pc+4] == OP_STORE2) {
-				opt = EmitMovEBXEDI(vm, (vm->dataMask & ~1));
+				opt = EmitMovEBXEDI(vm, (vm->dataMask));
 				EmitString( "B8" );			// mov	eax, 0x12345678
 				Emit4( Constant4() );
 //				if (!opt) {
