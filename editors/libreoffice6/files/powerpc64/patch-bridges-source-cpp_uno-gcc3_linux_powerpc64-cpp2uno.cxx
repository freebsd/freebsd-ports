--- bridges/source/cpp_uno/gcc3_linux_powerpc64/cpp2uno.cxx.orig	2020-04-04 12:03:03.236554000 -0500
+++ bridges/source/cpp_uno/gcc3_linux_powerpc64/cpp2uno.cxx	2020-04-08 14:28:30.208034000 -0500
@@ -341,7 +341,7 @@
 
 static typelib_TypeClass cpp_mediate(
     sal_uInt64 nOffsetAndIndex,
-        void ** gpreg, void ** fpreg, long sp,
+        void ** gpreg, void ** fpreg, long fp,
     sal_Int64 * pRegisterReturn /* space for register return */ )
 {
     static_assert(sizeof(sal_Int64)==sizeof(void *), "### unexpected!");
@@ -349,8 +349,8 @@
     sal_Int32 nVtableOffset = (nOffsetAndIndex >> 32);
     sal_Int32 nFunctionIndex = (nOffsetAndIndex & 0xFFFFFFFF);
 
-    long sf = *(long*)sp;
-    void ** ovrflw = (void**)(sf + PARAMSAVE + 64);
+    /* XXX: This is the stack frame!!!! */
+    void ** ovrflw = (void**)(fp + PARAMSAVE + 64);
 
     // gpreg:  [ret *], this, [other gpr params]
     // fpreg:  [fpr params]
@@ -513,18 +513,22 @@
     return eRet;
 }
 
-extern "C" void privateSnippetExecutor( ... )
+extern "C" void privateSnippetExecutor( uint64_t a, ... )
 {
+    va_list args, fpargs;
     sal_uInt64 gpreg[ppc64::MAX_GPR_REGS];
 
-    register long r3 asm("r3"); gpreg[0] = r3;
-    register long r4 asm("r4"); gpreg[1] = r4;
-    register long r5 asm("r5"); gpreg[2] = r5;
-    register long r6 asm("r6"); gpreg[3] = r6;
-    register long r7 asm("r7"); gpreg[4] = r7;
-    register long r8 asm("r8"); gpreg[5] = r8;
-    register long r9 asm("r9"); gpreg[6] = r9;
-    register long r10 asm("r10"); gpreg[7] = r10;
+    va_start(args, a);
+    va_copy(fpargs, args);
+    /* Start with all the GPRs */
+    gpreg[0] = a;
+    gpreg[1] = va_arg(args, uint64_t);
+    gpreg[2] = va_arg(args, uint64_t);
+    gpreg[3] = va_arg(args, uint64_t);
+    gpreg[4] = va_arg(args, uint64_t);
+    gpreg[5] = va_arg(args, uint64_t);
+    gpreg[6] = va_arg(args, uint64_t);
+    gpreg[7] = va_arg(args, uint64_t);
 
     double fpreg[ppc64::MAX_SSE_REGS];
 
@@ -547,11 +551,11 @@
           "fr10", "fr11", "fr12", "fr13"
     );
 
-    register long r11 asm("r11");
-    const long nOffsetAndIndex = r11;
+    long nOffsetAndIndex;
+    long fp;
 
-    register long r1 asm("r1");
-    const long sp = r1;
+    __asm __volatile("mr %0, 11\n" : "=r"(nOffsetAndIndex));
+    fp = (long)__builtin_frame_address(0);
 
 #if defined(_CALL_ELF) && _CALL_ELF == 2
     volatile long nRegReturn[2];
@@ -560,7 +564,7 @@
 #endif
 
     typelib_TypeClass aType =
-        cpp_mediate( nOffsetAndIndex, (void**)gpreg, (void**)fpreg, sp, (sal_Int64*)nRegReturn);
+        cpp_mediate( nOffsetAndIndex, (void**)gpreg, (void**)fpreg, fp, (sal_Int64*)nRegReturn);
 
     switch( aType )
     {
