--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp.cxx.orig
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp.cxx
@@ -26,6 +26,12 @@
 
 #include <stdlib.h>
 
+#include <exception>
+#include <malloc.h>
+#include <typeinfo>
+
+#include <com/sun/star/uno/Exception.hpp>
+#include <com/sun/star/uno/RuntimeException.hpp>
 #include <com/sun/star/uno/genfunc.hxx>
 #include <uno/data.h>
 
@@ -42,10 +48,68 @@
 
 using namespace ::rtl;
 using namespace ::com::sun::star::uno;
-
-void MapReturn(long r3, double dret, typelib_TypeClass eTypeClass, void *pRegisterReturn)
+#ifdef __GLIBCXX__
+using CPPU_CURRENT_NAMESPACE::__cxa_exception;
+using CPPU_CURRENT_NAMESPACE::__cxa_get_globals;
+#else
+using __cxxabiv1::__cxa_exception;
+using __cxxabiv1::__cxa_current_primary_exception;
+using __cxxabiv1::__cxa_decrement_exception_refcount;
+#endif
+
+namespace ppc64
 {
-    switch (eTypeClass)
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+    bool is_complex_struct(const typelib_TypeDescription * type)
+    {
+        const typelib_CompoundTypeDescription * p
+            = reinterpret_cast< const typelib_CompoundTypeDescription * >(type);
+        for (sal_Int32 i = 0; i < p->nMembers; ++i)
+        {
+            if (p->ppTypeRefs[i]->eTypeClass == typelib_TypeClass_STRUCT ||
+                p->ppTypeRefs[i]->eTypeClass == typelib_TypeClass_EXCEPTION)
+            {
+                typelib_TypeDescription * t = 0;
+                TYPELIB_DANGER_GET(&t, p->ppTypeRefs[i]);
+                bool b = is_complex_struct(t);
+                TYPELIB_DANGER_RELEASE(t);
+                if (b) {
+                    return true;
+                }
+            }
+            else if (!bridges::cpp_uno::shared::isSimpleType(p->ppTypeRefs[i]->eTypeClass))
+                return true;
+        }
+        if (p->pBaseTypeDescription != 0)
+            return is_complex_struct(&p->pBaseTypeDescription->aBase);
+        return false;
+    }
+#endif
+
+    bool return_in_hidden_param( typelib_TypeDescriptionReference *pTypeRef )
+    {
+        if (bridges::cpp_uno::shared::isSimpleType(pTypeRef))
+            return false;
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+        else if (pTypeRef->eTypeClass == typelib_TypeClass_STRUCT || pTypeRef->eTypeClass == typelib_TypeClass_EXCEPTION)
+        {
+            typelib_TypeDescription * pTypeDescr = 0;
+            TYPELIB_DANGER_GET( &pTypeDescr, pTypeRef );
+
+            //A Composite Type not larger than 16 bytes is returned in up to two GPRs
+            bool bRet = pTypeDescr->nSize > 16 || is_complex_struct(pTypeDescr);
+
+            TYPELIB_DANGER_RELEASE( pTypeDescr );
+            return bRet;
+        }
+#endif
+        return true;
+    }
+}
+
+extern "C" void MapReturn(long r3, long r4, double dret, typelib_TypeDescriptionReference* pReturnType, void *pRegisterReturn)
+{
+    switch (pReturnType->eTypeClass)
     {
     case typelib_TypeClass_HYPER:
     case typelib_TypeClass_UNSIGNED_HYPER:
@@ -67,10 +131,23 @@
             break;
     case typelib_TypeClass_FLOAT:
             *reinterpret_cast<float *>( pRegisterReturn ) = dret;
-	    break;
+        break;
     case typelib_TypeClass_DOUBLE:
             *reinterpret_cast<double *>( pRegisterReturn ) = dret;
             break;
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+    case typelib_TypeClass_STRUCT:
+    case typelib_TypeClass_EXCEPTION:
+            if (!ppc64::return_in_hidden_param(pReturnType))
+            {
+                sal_uInt64 *pRegisters = reinterpret_cast<sal_uInt64*>(pRegisterReturn);
+                pRegisters[0] = r3;
+                if (pReturnType->pType->nSize > 8)
+                    pRegisters[1] = r4;
+            }
+#else
+    (void)r4;
+#endif
     default:
             break;
     }
@@ -79,11 +156,13 @@
 namespace
 {
 //==================================================================================================
-static void callVirtualMethod(void * pThis, sal_uInt32 nVtableIndex, 
-	void * pRegisterReturn, typelib_TypeDescription * pReturnTypeDescr, 
+extern "C" void callVirtualMethod(void * pThis, sal_uInt32 nVtableIndex,
+    void * pRegisterReturn, typelib_TypeDescription * pReturnTypeDescr,
         sal_uInt64 *pStack, sal_uInt32 nStack,
         sal_uInt64 *pGPR, sal_uInt32 nGPR,
-        double *pFPR, sal_uInt32 nFPR)
+        double *pFPR, sal_uInt32 nFPR);
+
+#if 0
 {
     // Stack, if used, must be 16-bytes aligned
     if ( nStack )
@@ -99,13 +178,13 @@
         // Let's figure out what is really going on here
         {
                 fprintf( stderr, "= callVirtualMethod() =\nGPR's (%d): ", nGPR );
-                for ( int i = 0; i < nGPR; ++i )
+                for ( sal_uInt32 i = 0; i < nGPR; ++i )
                         fprintf( stderr, "0x%lx, ", pGPR[i] );
                 fprintf( stderr, "\nFPR's (%d): ", nFPR );
-                for ( int i = 0; i < nFPR; ++i ) 
-                        fprintf( stderr, "0x%lx (%f), ", pFPR[i], pFPR[i] );
+                for ( sal_uInt32 i = 0; i < nFPR; ++i )
+                        fprintf( stderr, "0x%lx (%lf), ", (sal_Int64)pFPR[i], pFPR[i] );
                 fprintf( stderr, "\nStack (%d): ", nStack );
-                for ( int i = 0; i < nStack; ++i )
+                for ( sal_uInt32 i = 0; i < nStack; ++i )
                         fprintf( stderr, "0x%lx, ", pStack[i] );
                 fprintf( stderr, "\n" );
         }
@@ -120,52 +199,40 @@
     pMethod += 8 * nVtableIndex;
     pMethod = *((sal_uInt64 *)pMethod);
 
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+    typedef void (* FunctionCall )(...);
+#else
     typedef void (* FunctionCall )( sal_uInt64, sal_uInt64, sal_uInt64, sal_uInt64, sal_uInt64, sal_uInt64, sal_uInt64, sal_uInt64 );
+#endif
     FunctionCall pFunc = (FunctionCall)pMethod;
 
     volatile double dret;
 
     //  fill registers
     __asm__ __volatile__ (
-                "ld   3,  0(%0)\n\t"
-                "ld   4,  8(%0)\n\t"
-                "ld   5, 16(%0)\n\t"
-                "ld   6, 24(%0)\n\t"
-                "ld   7, 32(%0)\n\t"
-                "ld   8, 40(%0)\n\t"
-                "ld   9, 48(%0)\n\t"
-                "ld  10, 56(%0)\n\t"
-                "lfd  1,  0(%1)\n\t"
-                "lfd  2,  8(%1)\n\t"
-                "lfd  3, 16(%1)\n\t"
-                "lfd  4, 24(%1)\n\t"
-                "lfd  5, 32(%1)\n\t"
-                "lfd  6, 40(%1)\n\t"
-                "lfd  7, 48(%1)\n\t"
-                "lfd  8, 56(%1)\n\t"
-                "lfd  9, 64(%1)\n\t"
-                "lfd 10, 72(%1)\n\t"
-                "lfd 11, 80(%1)\n\t"
-                "lfd 12, 88(%1)\n\t"
-                "lfd 13, 96(%1)\n\t"
-                : : "r" (pGPR), "r" (pFPR)
-          	: "r0", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10",
-                  "fr1", "fr2", "fr3", "fr4", "fr5", "fr6", "fr7", "fr8", "fr9",
-                  "fr10", "fr11", "fr12", "fr13"
+                "lfd  1,  0(%0)\n\t"
+                "lfd  2,  8(%0)\n\t"
+                "lfd  3, 16(%0)\n\t"
+                "lfd  4, 24(%0)\n\t"
+                "lfd  5, 32(%0)\n\t"
+                "lfd  6, 40(%0)\n\t"
+                "lfd  7, 48(%0)\n\t"
+                "lfd  8, 56(%0)\n\t"
+                "lfd  9, 64(%0)\n\t"
+                "lfd 10, 72(%0)\n\t"
+                "lfd 11, 80(%0)\n\t"
+                "lfd 12, 88(%0)\n\t"
+                "lfd 13, 96(%0)\n\t"
+                : : "r" (pFPR)
+              : "fr1", "fr2", "fr3", "fr4", "fr5", "fr6", "fr7", "fr8", "fr9",
+                "fr10", "fr11", "fr12", "fr13"
     );
 
     // tell gcc that r3 to r11 are not available to it for doing the TOC and exception munge on the func call
     register sal_uInt64 r3 asm("r3");
     register sal_uInt64 r4 asm("r4");
-    register sal_uInt64 r5 asm("r5");
-    register sal_uInt64 r6 asm("r6");
-    register sal_uInt64 r7 asm("r7");
-    register sal_uInt64 r8 asm("r8");
-    register sal_uInt64 r9 asm("r9");
-    register sal_uInt64 r10 asm("r10");
-    register sal_uInt64 r11 asm("r11");
-
-    (*pFunc)(r3, r4, r5, r6, r7, r8, r9, r10);
+
+    (*pFunc)(pGPR[0], pGPR[1], pGPR[2], pGPR[3], pGPR[4], pGPR[5], pGPR[6], pGPR[7]);
 
     // get return value
     __asm__ __volatile__ (
@@ -174,8 +241,9 @@
                 "fmr    %0,     1\n\t"
                 : "=f" (dret), "=r" (r3), "=r" (r4) : );
 
-    MapReturn(r3, dret, pReturnTypeDescr->eTypeClass, pRegisterReturn);
+    MapReturn(r3, r4, dret, reinterpret_cast<typelib_TypeDescriptionReference *>(pReturnTypeDescr), pRegisterReturn);
 }
+#endif
 
 // Macros for easier insertion of values to registers or stack
 // pSV - pointer to the source
@@ -185,23 +253,35 @@
 
 // The value in %xmm register is already prepared to be retrieved as a float,
 // thus we treat float and double the same
-#define INSERT_FLOAT( pSV, nr, pFPR, pDS, bOverflow ) \
-        if ( nr < ppc64::MAX_SSE_REGS ) \
+#define INSERT_FLOAT( pSV, nr, pFPR, nGPR, pDS, bOverFlow ) \
+        if ( nGPR < ppc64::MAX_GPR_REGS ) \
+                ++nGPR;                   \
+        if ( nr < ppc64::MAX_SSE_REGS )   \
                 pFPR[nr++] = *reinterpret_cast<float *>( pSV ); \
         else \
-        	bOverFlow = true; \
+            bOverFlow = true; \
         if (bOverFlow) \
                 *pDS++ = *reinterpret_cast<sal_uInt64 *>( pSV ); // verbatim!
 
-#define INSERT_DOUBLE( pSV, nr, pFPR, pDS, bOverflow ) \
-        if ( nr < ppc64::MAX_SSE_REGS ) \
+#define INSERT_DOUBLE( pSV, nr, pFPR, nGPR, pDS, bOverFlow ) \
+        if ( nGPR < ppc64::MAX_GPR_REGS ) \
+                ++nGPR;                   \
+        if ( nr < ppc64::MAX_SSE_REGS )   \
                 pFPR[nr++] = *reinterpret_cast<double *>( pSV ); \
         else \
-        	bOverFlow = true; \
+            bOverFlow = true; \
         if (bOverFlow) \
                 *pDS++ = *reinterpret_cast<sal_uInt64 *>( pSV ); // verbatim!
 
-#define INSERT_INT64( pSV, nr, pGPR, pDS, bOverflow ) \
+#define INSERT_INT64( pSV, nr, pGPR, pDS, bOverFlow ) \
+        if ( nr < ppc64::MAX_GPR_REGS ) \
+                pGPR[nr++] = *reinterpret_cast<sal_Int64 *>( pSV ); \
+        else \
+        bOverFlow = true; \
+    if (bOverFlow) \
+                *pDS++ = *reinterpret_cast<sal_Int64 *>( pSV );
+
+#define INSERT_UINT64( pSV, nr, pGPR, pDS, bOverFlow ) \
         if ( nr < ppc64::MAX_GPR_REGS ) \
                 pGPR[nr++] = *reinterpret_cast<sal_uInt64 *>( pSV ); \
         else \
@@ -209,7 +289,15 @@
 	if (bOverFlow) \
                 *pDS++ = *reinterpret_cast<sal_uInt64 *>( pSV );
 
-#define INSERT_INT32( pSV, nr, pGPR, pDS, bOverflow ) \
+#define INSERT_INT32( pSV, nr, pGPR, pDS, bOverFlow ) \
+        if ( nr < ppc64::MAX_GPR_REGS ) \
+                pGPR[nr++] = *reinterpret_cast<sal_Int32 *>( pSV ); \
+        else \
+                bOverFlow = true; \
+        if (bOverFlow) \
+                *pDS++ = *reinterpret_cast<sal_Int32 *>( pSV );
+
+#define INSERT_UINT32( pSV, nr, pGPR, pDS, bOverFlow ) \
         if ( nr < ppc64::MAX_GPR_REGS ) \
                 pGPR[nr++] = *reinterpret_cast<sal_uInt32 *>( pSV ); \
         else \
@@ -217,7 +305,15 @@
         if (bOverFlow) \
                 *pDS++ = *reinterpret_cast<sal_uInt32 *>( pSV );
 
-#define INSERT_INT16( pSV, nr, pGPR, pDS, bOverflow ) \
+#define INSERT_INT16( pSV, nr, pGPR, pDS, bOverFlow ) \
+        if ( nr < ppc64::MAX_GPR_REGS ) \
+                pGPR[nr++] = *reinterpret_cast<sal_Int16 *>( pSV ); \
+        else \
+                bOverFlow = true; \
+        if (bOverFlow) \
+                *pDS++ = *reinterpret_cast<sal_Int16 *>( pSV );
+
+#define INSERT_UINT16( pSV, nr, pGPR, pDS, bOverFlow ) \
         if ( nr < ppc64::MAX_GPR_REGS ) \
                 pGPR[nr++] = *reinterpret_cast<sal_uInt16 *>( pSV ); \
         else \
@@ -225,7 +321,15 @@
         if (bOverFlow) \
                 *pDS++ = *reinterpret_cast<sal_uInt16 *>( pSV );
 
-#define INSERT_INT8( pSV, nr, pGPR, pDS, bOverflow ) \
+#define INSERT_INT8( pSV, nr, pGPR, pDS, bOverFlow ) \
+        if ( nr < ppc64::MAX_GPR_REGS ) \
+                pGPR[nr++] = *reinterpret_cast<sal_Int8 *>( pSV ); \
+        else \
+                bOverFlow = true; \
+        if (bOverFlow) \
+                *pDS++ = *reinterpret_cast<sal_Int8 *>( pSV );
+
+#define INSERT_UINT8( pSV, nr, pGPR, pDS, bOverFlow ) \
         if ( nr < ppc64::MAX_GPR_REGS ) \
                 pGPR[nr++] = *reinterpret_cast<sal_uInt8 *>( pSV ); \
         else \
@@ -337,19 +441,23 @@
                                 INSERT_INT32( pCppArgs[nPos], nGPR, pGPR, pStack, bOverFlow );
                                 break;
                         case typelib_TypeClass_SHORT:
+                                INSERT_INT16( pCppArgs[nPos], nGPR, pGPR, pStack, bOverFlow );
+                                break;
                         case typelib_TypeClass_CHAR:
                         case typelib_TypeClass_UNSIGNED_SHORT:
                                 INSERT_INT16( pCppArgs[nPos], nGPR, pGPR, pStack, bOverFlow );
                                 break;
                         case typelib_TypeClass_BOOLEAN:
+                                INSERT_UINT8( pCppArgs[nPos], nGPR, pGPR, pStack, bOverFlow );
+                                break;
                         case typelib_TypeClass_BYTE:
                                 INSERT_INT8( pCppArgs[nPos], nGPR, pGPR, pStack, bOverFlow );
                                 break;
                         case typelib_TypeClass_FLOAT:
-                                INSERT_FLOAT( pCppArgs[nPos], nFPR, pFPR, pStack, bOverFlow );
-				break;
+                                INSERT_FLOAT( pCppArgs[nPos], nFPR, pFPR, nGPR, pStack, bOverFlow );
+								break;
                         case typelib_TypeClass_DOUBLE:
-                                INSERT_DOUBLE( pCppArgs[nPos], nFPR, pFPR, pStack, bOverFlow );
+                                INSERT_DOUBLE( pCppArgs[nPos], nFPR, pFPR, nGPR, pStack, bOverFlow );
                                 break;
                         }
 
@@ -448,9 +556,18 @@
 	}
  	catch (...)
  	{
+		__cxa_exception *header;
+#ifdef __GLIBCXX__
+		header = __cxa_get_globals()->caughtExceptions;
+#else
+		header = reinterpret_cast<__cxa_exception *>( __cxa_current_primary_exception() );
+		if (header) {
+			__cxa_decrement_exception_refcount( header );
+			header--;
+		}
+#endif
   		// fill uno exception
-		fillUnoException( CPPU_CURRENT_NAMESPACE::__cxa_get_globals()->caughtExceptions, 
-                                  *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+		CPPU_CURRENT_NAMESPACE::fillUnoException( header, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
         
 		// temporary params
 		for ( ; nTempIndizes--; )
@@ -475,8 +592,8 @@
 	void * pReturn, void * pArgs[], uno_Any ** ppException )
 {
 	// is my surrogate
-        bridges::cpp_uno::shared::UnoInterfaceProxy * pThis 
-            = static_cast< bridges::cpp_uno::shared::UnoInterfaceProxy *> (pUnoI);
+        ::bridges::cpp_uno::shared::UnoInterfaceProxy * pThis 
+            = static_cast< ::bridges::cpp_uno::shared::UnoInterfaceProxy *> (pUnoI);
 	typelib_InterfaceTypeDescription * pTypeDescr = pThis->pTypeDescr;
 	
 	switch (pMemberDescr->eTypeClass)
@@ -484,8 +601,8 @@
 	case typelib_TypeClass_INTERFACE_ATTRIBUTE:
 	{
 
-        VtableSlot aVtableSlot(
-            getVtableSlot(
+        ::bridges::cpp_uno::shared::VtableSlot aVtableSlot(
+            ::bridges::cpp_uno::shared::getVtableSlot(
                 reinterpret_cast<
                     typelib_InterfaceAttributeTypeDescription const * >(
                         pMemberDescr)));
@@ -529,8 +646,8 @@
 	case typelib_TypeClass_INTERFACE_METHOD:
 	{
 
-        VtableSlot aVtableSlot(
-            getVtableSlot(
+        ::bridges::cpp_uno::shared::VtableSlot aVtableSlot(
+            ::bridges::cpp_uno::shared::getVtableSlot(
                 reinterpret_cast<
                     typelib_InterfaceMethodTypeDescription const * >(
                         pMemberDescr)));

