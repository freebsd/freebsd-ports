--- code/qcommon/vm_interpreted.c.orig	2008-08-23 22:45:30 UTC
+++ code/qcommon/vm_interpreted.c
@@ -526,18 +526,20 @@ nextInstruction2:
 
 //VM_LogSyscalls( (int *)&image[ programStack + 4 ] );
 				{
-					intptr_t* argptr = (intptr_t *)&image[ programStack + 4 ];
-				#if __WORDSIZE == 64
-				// the vm has ints on the stack, we expect
-				// longs so we have to convert it
-					intptr_t argarr[16];
-					int i;
-					for (i = 0; i < 16; ++i) {
-						argarr[i] = *(int*)&image[ programStack + 4 + 4*i ];
+					// the vm has ints on the stack, we expect
+					// pointers so we might have to convert it
+					if (sizeof(intptr_t) != sizeof(int)) {
+						intptr_t argarr[16];
+						int *imagePtr = (int *)&image[programStack];
+						int i;
+						for (i = 0; i < 16; ++i) {
+							argarr[i] = *(++imagePtr);
+						}
+						r = vm->systemCall( argarr );
+					} else {
+						intptr_t* argptr = (intptr_t *)&image[ programStack + 4 ];
+						r = vm->systemCall( argptr );
 					}
-					argptr = argarr;
-				#endif
-					r = vm->systemCall( argptr );
 				}
 
 #ifdef DEBUG_VM
