--- hotspot/src/share/vm/interpreter/bytecodeInterpreter.cpp	Mon Apr 25 21:03:53 2016 +0000
+++ hotspot/src/share/vm/interpreter/bytecodeInterpreter.cpp	Tue Apr 26 02:49:59 2016 +0100
@@ -593,8 +593,9 @@
 /* 0xDC */ &&opc_default,     &&opc_default,        &&opc_default,      &&opc_default,
 
 /* 0xE0 */ &&opc_default,     &&opc_default,        &&opc_default,      &&opc_default,
-/* 0xE4 */ &&opc_default,     &&opc_fast_aldc,      &&opc_fast_aldc_w,  &&opc_return_register_finalizer,
-/* 0xE8 */ &&opc_invokehandle,&&opc_default,        &&opc_default,      &&opc_default,
+/* 0xE4 */ &&opc_default,     &&opc_default,        &&opc_fast_aldc,    &&opc_fast_aldc_w,
+/* 0xE8 */ &&opc_return_register_finalizer,
+                              &&opc_invokehandle,   &&opc_default,      &&opc_default,
 /* 0xEC */ &&opc_default,     &&opc_default,        &&opc_default,      &&opc_default,
 
 /* 0xF0 */ &&opc_default,     &&opc_default,        &&opc_default,      &&opc_default,
