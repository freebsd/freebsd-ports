--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/cpp2uno.cxx.orig
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/cpp2uno.cxx
@@ -28,6 +28,7 @@
 #include <uno/data.h>
 #include <typelib/typedescription.hxx>
 
+#include <osl/endian.h>
 #include "bridges/cpp_uno/shared/bridge.hxx"
 #include "bridges/cpp_uno/shared/cppinterfaceproxy.hxx"
 #include "bridges/cpp_uno/shared/types.hxx"
@@ -37,6 +38,11 @@
 #include <stdio.h>
 #include <string.h>
 
+#ifdef OSL_BIGENDIAN
+#define IS_BIG_ENDIAN 1
+#else
+#define IS_BIG_ENDIAN 0
+#endif
 
 using namespace ::com::sun::star::uno;
 
@@ -70,12 +76,18 @@
 	
 	void * pUnoReturn = 0;
 	void * pCppReturn = 0; // complex return ptr: if != 0 && != pUnoReturn, reconversion need
-	
+	double * pFprReturn = reinterpret_cast< double * >( fpreg );
+	typelib_TypeClass eFprBase = typelib_TypeClass_VOID;
+	sal_Int32 nFprMembers = 0;
+
 	if (pReturnTypeDescr)
 	{
-		if (bridges::cpp_uno::shared::isSimpleType( pReturnTypeDescr ))
+		if (!ppc64::return_in_hidden_param( pReturnTypeRef ))
 		{
-			pUnoReturn = pRegisterReturn; // direct way for simple types
+			nFprMembers = ppc64::return_in_fprs( pReturnTypeRef, eFprBase );
+			pUnoReturn = (nFprMembers != 0
+						  ? alloca( pReturnTypeDescr->nSize )
+						  : pRegisterReturn); // direct way for simple types
 		}
 		else // complex return via ptr (pCppReturn)
 		{
@@ -144,14 +156,14 @@
                 case typelib_TypeClass_BYTE:
                 case typelib_TypeClass_BOOLEAN:
                     if (ng < ppc64::MAX_GPR_REGS)
-					{
-                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)gpreg) + (sizeof(void*)-1));
+                    {
+                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)gpreg) + 7*IS_BIG_ENDIAN);
                         ng++;
                         gpreg++;
                     }
                     else
-					{
-                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)ovrflw) + (sizeof(void*)-1));
+                    {
+                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)ovrflw) + 7*IS_BIG_ENDIAN);
                         bOverFlowUsed = true;
                     }
                     if (bOverFlowUsed) ovrflw++;
@@ -160,14 +172,14 @@
                 case typelib_TypeClass_SHORT:
                 case typelib_TypeClass_UNSIGNED_SHORT:
                     if (ng < ppc64::MAX_GPR_REGS)
-					{
-                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)gpreg) + (sizeof(void*)-2));
+                    {
+                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)gpreg) + 6*IS_BIG_ENDIAN);
                         ng++;
                         gpreg++;
                     }
                     else
-					{
-                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)ovrflw) + (sizeof(void*)-2));
+                    {
+                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)ovrflw) + 6*IS_BIG_ENDIAN);
                         bOverFlowUsed = true;
                     }
                     if (bOverFlowUsed) ovrflw++;
@@ -176,14 +188,14 @@
                 case typelib_TypeClass_LONG:
                 case typelib_TypeClass_UNSIGNED_LONG:
                     if (ng < ppc64::MAX_GPR_REGS)
-					{
-                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)gpreg) + (sizeof(void*)-4));
+                    {
+                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)gpreg) + 4*IS_BIG_ENDIAN);
                         ng++;
                         gpreg++;
                     }
                     else
-					{
-                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)ovrflw) + (sizeof(void*)-4));
+                    {
+                        pCppArgs[nPos] = pUnoArgs[nPos] = (((char *)ovrflw) + 4*IS_BIG_ENDIAN);
                         bOverFlowUsed = true;
                     }
                     if (bOverFlowUsed) ovrflw++;
@@ -319,6 +331,23 @@
 		if (pReturnTypeDescr)
 		{
 			typelib_TypeClass eRet = (typelib_TypeClass)pReturnTypeDescr->eTypeClass;
+			if (nFprMembers != 0)
+			{
+				for (sal_Int32 i = 0; i < nFprMembers; ++i)
+					pFprReturn[i] = (eFprBase == typelib_TypeClass_FLOAT
+									 ? static_cast< float * >( pUnoReturn )[i]
+									 : static_cast< double * >( pUnoReturn )[i]);
+				eRet = ppc64::TYPECLASS_FPRS;
+			}
+#ifdef OSL_BIGENDIAN
+			else if (eRet == typelib_TypeClass_STRUCT && !pCppReturn && pReturnTypeDescr->nSize < 8)
+			{
+				sal_uInt64 n = 0;
+				memcpy( reinterpret_cast< char * >( &n ) + 8 - pReturnTypeDescr->nSize,
+						pRegisterReturn, pReturnTypeDescr->nSize );
+				*reinterpret_cast< sal_uInt64 * >( pRegisterReturn ) = n;
+			}
+#endif
 			TYPELIB_DANGER_RELEASE( pReturnTypeDescr );
 			return eRet;
 		}
@@ -327,21 +356,25 @@
 	}
 }
 
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+#  define PARAMSAVE 32
+#else
+#  define PARAMSAVE 48
+#endif
 
-//==================================================================================================
-static typelib_TypeClass cpp_mediate(
-	sal_uInt64 nOffsetAndIndex,
+extern "C" typelib_TypeClass cpp_mediate(
+    sal_uInt64 nOffsetAndIndex,
         void ** gpreg, void ** fpreg, long sp,
-	sal_Int64 * pRegisterReturn /* space for register return */ )
+    sal_Int64 * pRegisterReturn /* space for register return */ )
 {
-    OSL_ENSURE( sizeof(sal_Int64)==sizeof(void *), "### unexpected!" );
+    static_assert(sizeof(sal_Int64)==sizeof(void *), "### unexpected!");
 
     sal_Int32 nVtableOffset = (nOffsetAndIndex >> 32);
     sal_Int32 nFunctionIndex = (nOffsetAndIndex & 0xFFFFFFFF);
 
     long sf = *(long*)sp;
-    void ** ovrflw = (void**)(sf + 112);
-	
+    void ** ovrflw = (void**)(sf + PARAMSAVE + 64);
+
     // gpreg:  [ret *], this, [other gpr params]
     // fpreg:  [fpr params]
     // ovrflw: [gpr or fpr params (properly aligned)]
@@ -501,54 +534,52 @@
 	return eRet;
 }
 
-extern "C" void privateSnippetExecutor( ... )
+extern "C" void privateSnippetExecutor( ... );
+#if 0
 {
-    volatile long nOffsetAndIndex;
+    sal_uInt64 gpreg[ppc64::MAX_GPR_REGS];
 
-    //mr %r3, %r11            # move into arg1 the 64bit value passed from OOo
-    __asm__ __volatile__ (
-                "mr     %0,    11\n\t"
-                : "=r" (nOffsetAndIndex) : );
+    register long r3 asm("r3"); gpreg[0] = r3;
+    register long r4 asm("r4"); gpreg[1] = r4;
+    register long r5 asm("r5"); gpreg[2] = r5;
+    register long r6 asm("r6"); gpreg[3] = r6;
+    register long r7 asm("r7"); gpreg[4] = r7;
+    register long r8 asm("r8"); gpreg[5] = r8;
+    register long r9 asm("r9"); gpreg[6] = r9;
+    register long r10 asm("r10"); gpreg[7] = r10;
 
-    sal_uInt64 gpreg[ppc64::MAX_GPR_REGS];
     double fpreg[ppc64::MAX_SSE_REGS];
 
     __asm__ __volatile__ (
-        "std 3,   0(%0)\t\n"
-        "std 4,   8(%0)\t\n"
-        "std 5,  16(%0)\t\n"
-        "std 6,  24(%0)\t\n"
-        "std 7,  32(%0)\t\n"
-        "std 8,  40(%0)\t\n"
-        "std 9,  48(%0)\t\n"
-        "std 10, 56(%0)\t\n"
-        "stfd 1,   0(%1)\t\n"
-        "stfd 2,   8(%1)\t\n"
-        "stfd 3,  16(%1)\t\n"
-        "stfd 4,  24(%1)\t\n"
-        "stfd 5,  32(%1)\t\n"
-        "stfd 6,  40(%1)\t\n"
-        "stfd 7,  48(%1)\t\n"
-        "stfd 8,  56(%1)\t\n"
-        "stfd 9,  64(%1)\t\n"
-        "stfd 10, 72(%1)\t\n"
-        "stfd 11, 80(%1)\t\n"
-        "stfd 12, 88(%1)\t\n"
-        "stfd 13, 96(%1)\t\n"
-	: : "r" (gpreg), "r" (fpreg) 
-        : "r0", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10",
-          "fr1", "fr2", "fr3", "fr4", "fr5", "fr6", "fr7", "fr8", "fr9",
+        "stfd 1,   0(%0)\t\n"
+        "stfd 2,   8(%0)\t\n"
+        "stfd 3,  16(%0)\t\n"
+        "stfd 4,  24(%0)\t\n"
+        "stfd 5,  32(%0)\t\n"
+        "stfd 6,  40(%0)\t\n"
+        "stfd 7,  48(%0)\t\n"
+        "stfd 8,  56(%0)\t\n"
+        "stfd 9,  64(%0)\t\n"
+        "stfd 10, 72(%0)\t\n"
+        "stfd 11, 80(%0)\t\n"
+        "stfd 12, 88(%0)\t\n"
+        "stfd 13, 96(%0)\t\n"
+    : : "r" (fpreg)
+        : "fr1", "fr2", "fr3", "fr4", "fr5", "fr6", "fr7", "fr8", "fr9",
           "fr10", "fr11", "fr12", "fr13"
     );
 
-    volatile long sp;
+    register long r11 asm("r11");
+    const long nOffsetAndIndex = r11;
 
-    //stack pointer
-    __asm__ __volatile__ (
-                "mr     %0,    1\n\t"
-                : "=r" (sp) : );
+    register long r1 asm("r1");
+    const long sp = r1;
 
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+    volatile long nRegReturn[2];
+#else
     volatile long nRegReturn[1];
+#endif
 
     typelib_TypeClass aType =
         cpp_mediate( nOffsetAndIndex, (void**)gpreg, (void**)fpreg, sp, (sal_Int64*)nRegReturn);
@@ -591,11 +622,20 @@
         default:
             __asm__( "ld 3,%0\n\t" 
                 : : "m" (nRegReturn[0]) );
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+            __asm__( "ld 4,%0\n\t"
+                : : "m" (nRegReturn[1]) );
+#endif
             break;
     }
 }
+#endif
 
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+const int codeSnippetSize = 32;
+#else
 const int codeSnippetSize = 24;
+#endif
 
 unsigned char *  codeSnippet( unsigned char * code, sal_Int32 nFunctionIndex, sal_Int32 nVtableOffset, 
                               bool simpleRetType)
@@ -609,10 +649,22 @@
 
     if ( !simpleRetType )
         nOffsetAndIndex |= 0x80000000;
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+    unsigned int *raw = (unsigned int *)&code[0];
 
+    raw[0] = 0xe96c0018;        /* 0:   ld      11,2f-0b(12)    */
+    raw[1] = 0xe98c0010;        /*      ld      12,1f-0b(12)    */
+    raw[2] = 0x7d8903a6;        /*      mtctr   12              */
+    raw[3] = 0x4e800420;        /*      bctr                    */
+                                /* 1:   .quad   function_addr   */
+                                /* 2:   .quad   context         */
+    *(void **)&raw[4] = (void *)privateSnippetExecutor;
+    *(void **)&raw[6] = (void*)nOffsetAndIndex;
+#else
     void ** raw = (void **)&code[0];
     memcpy(raw, (char*) privateSnippetExecutor, 16);
     raw[2] = (void*) nOffsetAndIndex;
+#endif
 #ifdef CMC_DEBUG
     fprintf(stderr, "in: offset/index is %x %x %d, %lx\n", 
 	nFunctionIndex, nVtableOffset, !simpleRetType, raw[2]);
@@ -681,7 +733,7 @@
             (s++)->fn = code + writetoexecdiff;
             code = codeSnippet(
                 code, functionOffset++, vtableOffset,
-                bridges::cpp_uno::shared::isSimpleType(
+                !ppc64::return_in_hidden_param(
                     reinterpret_cast<
                     typelib_InterfaceAttributeTypeDescription * >(
                         member)->pAttributeTypeRef));
@@ -700,7 +752,7 @@
             (s++)->fn = code + writetoexecdiff;
             code = codeSnippet(
                 code, functionOffset++, vtableOffset,
-                bridges::cpp_uno::shared::isSimpleType(
+                !ppc64::return_in_hidden_param(
                     reinterpret_cast<
                     typelib_InterfaceMethodTypeDescription * >(
                         member)->pReturnTypeRef));
