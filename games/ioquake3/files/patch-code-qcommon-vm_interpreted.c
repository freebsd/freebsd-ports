--- code/qcommon/vm_interpreted.c	2009/11/01 19:58:07	1717
+++ code/qcommon/vm_interpreted.c	2010/01/16 10:55:51	1772
@@ -516,18 +516,20 @@
 
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
