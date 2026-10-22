--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp.cxx.orig	2026-09-18 00:49:04 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/uno2cpp.cxx
@@ -33,6 +33,7 @@
 #include <com/sun/star/uno/Exception.hpp>
 #include <com/sun/star/uno/RuntimeException.hpp>
 #include <com/sun/star/uno/genfunc.hxx>
+#include <osl/endian.h>
 #include <uno/data.h>
 
 #include "bridges/cpp_uno/shared/bridge.hxx"
@@ -84,7 +85,61 @@ namespace ppc64
             return is_complex_struct(&p->pBaseTypeDescription->aBase);
         return false;
     }
+
+    static bool collect_fpr_members(const typelib_TypeDescription * type,
+                                    typelib_TypeClass & eBase, sal_Int32 & nMembers)
+    {
+        const typelib_CompoundTypeDescription * p
+            = reinterpret_cast< const typelib_CompoundTypeDescription * >(type);
+        if (p->pBaseTypeDescription != 0
+            && !collect_fpr_members(&p->pBaseTypeDescription->aBase, eBase, nMembers))
+            return false;
+        for (sal_Int32 i = 0; i < p->nMembers; ++i)
+        {
+            typelib_TypeClass eClass = p->ppTypeRefs[i]->eTypeClass;
+            if (eClass == typelib_TypeClass_STRUCT)
+            {
+                typelib_TypeDescription * t = 0;
+                TYPELIB_DANGER_GET(&t, p->ppTypeRefs[i]);
+                bool b = collect_fpr_members(t, eBase, nMembers);
+                TYPELIB_DANGER_RELEASE(t);
+                if (!b)
+                    return false;
+            }
+            else if (eClass == typelib_TypeClass_FLOAT || eClass == typelib_TypeClass_DOUBLE)
+            {
+                if (eBase == typelib_TypeClass_VOID)
+                    eBase = eClass;
+                else if (eBase != eClass)
+                    return false;
+                ++nMembers;
+            }
+            else
+                return false;
+        }
+        return true;
+    }
+#endif
+
+    sal_Int32 return_in_fprs( typelib_TypeDescriptionReference *pTypeRef, typelib_TypeClass & eBase )
+    {
+        eBase = typelib_TypeClass_VOID;
+#if defined(_CALL_ELF) && _CALL_ELF == 2
+        if (pTypeRef->eTypeClass == typelib_TypeClass_STRUCT)
+        {
+            typelib_TypeDescription * pTypeDescr = 0;
+            TYPELIB_DANGER_GET( &pTypeDescr, pTypeRef );
+            sal_Int32 nMembers = 0;
+            if (!collect_fpr_members(pTypeDescr, eBase, nMembers) || nMembers > 8)
+                nMembers = 0;
+            TYPELIB_DANGER_RELEASE( pTypeDescr );
+            return nMembers;
+        }
+#else
+        (void)pTypeRef;
 #endif
+        return 0;
+    }
 
     bool return_in_hidden_param( typelib_TypeDescriptionReference *pTypeRef )
     {
@@ -93,6 +148,10 @@ namespace ppc64
 #if defined(_CALL_ELF) && _CALL_ELF == 2
         else if (pTypeRef->eTypeClass == typelib_TypeClass_STRUCT || pTypeRef->eTypeClass == typelib_TypeClass_EXCEPTION)
         {
+            typelib_TypeClass eBase;
+            if (return_in_fprs(pTypeRef, eBase) != 0)
+                return false;
+
             typelib_TypeDescription * pTypeDescr = 0;
             TYPELIB_DANGER_GET( &pTypeDescr, pTypeRef );
 
@@ -107,7 +166,8 @@ namespace ppc64
     }
 }
 
-extern "C" void MapReturn(long r3, long r4, double dret, typelib_TypeDescriptionReference* pReturnType, void *pRegisterReturn)
+extern "C" void MapReturn(long r3, long r4, typelib_TypeDescriptionReference* pReturnType, void *pRegisterReturn,
+    double dret, double f2, double f3, double f4, double f5, double f6, double f7, double f8)
 {
     switch (pReturnType->eTypeClass)
     {
@@ -138,15 +198,41 @@ extern "C" void MapReturn(long r3, long
 #if defined(_CALL_ELF) && _CALL_ELF == 2
     case typelib_TypeClass_STRUCT:
     case typelib_TypeClass_EXCEPTION:
-            if (!ppc64::return_in_hidden_param(pReturnType))
+        {
+            typelib_TypeClass eBase;
+            sal_Int32 nMembers = ppc64::return_in_fprs(pReturnType, eBase);
+            if (nMembers != 0)
             {
-                sal_uInt64 *pRegisters = reinterpret_cast<sal_uInt64*>(pRegisterReturn);
-                pRegisters[0] = r3;
-                if (pReturnType->pType->nSize > 8)
-                    pRegisters[1] = r4;
+                const double fpr[8] = { dret, f2, f3, f4, f5, f6, f7, f8 };
+                for (sal_Int32 i = 0; i < nMembers; ++i)
+                {
+                    if (eBase == typelib_TypeClass_FLOAT)
+                        reinterpret_cast<float *>( pRegisterReturn )[i] = fpr[i];
+                    else
+                        reinterpret_cast<double *>( pRegisterReturn )[i] = fpr[i];
+                }
             }
+            else if (!ppc64::return_in_hidden_param(pReturnType))
+            {
+                char *p = reinterpret_cast<char *>(pRegisterReturn);
+                sal_Int32 nSize = pReturnType->pType->nSize;
+                if (nSize > 8)
+                {
+                    memcpy(p, &r3, 8);
+                    memcpy(p + 8, &r4, nSize - 8);
+                }
+                else
+#ifdef OSL_BIGENDIAN
+                    memcpy(p, reinterpret_cast<char *>(&r3) + 8 - nSize, nSize);
+#else
+                    memcpy(p, &r3, nSize);
+#endif
+            }
+        }
+        break;
 #else
     (void)r4;
+    (void)f2; (void)f3; (void)f4; (void)f5; (void)f6; (void)f7; (void)f8;
 #endif
     default:
             break;
@@ -369,7 +455,7 @@ static void cpp_call(
 #ifdef CMC_DEBUG
 		fprintf(stderr, "return type is %d\n", pReturnTypeDescr->eTypeClass);
 #endif
-		if (bridges::cpp_uno::shared::isSimpleType( pReturnTypeDescr ))
+		if (!ppc64::return_in_hidden_param( pReturnTypeRef ))
 		{
 			pCppReturn = pUnoReturn; // direct way for simple types
 #ifdef CMC_DEBUG
