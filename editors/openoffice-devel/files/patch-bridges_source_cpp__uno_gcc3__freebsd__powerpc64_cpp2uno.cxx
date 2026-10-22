--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/cpp2uno.cxx.orig	2026-09-18 00:49:04 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/cpp2uno.cxx
@@ -76,12 +76,18 @@ static typelib_TypeClass cpp2uno_call(
 
 	void * pUnoReturn = 0;
 	void * pCppReturn = 0; // complex return ptr: if != 0 && != pUnoReturn, reconversion need
+	double * pFprReturn = reinterpret_cast< double * >( fpreg );
+	typelib_TypeClass eFprBase = typelib_TypeClass_VOID;
+	sal_Int32 nFprMembers = 0;
 
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
@@ -325,6 +331,23 @@ static typelib_TypeClass cpp2uno_call(
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
@@ -710,7 +733,7 @@ unsigned char * bridges::cpp_uno::shared
             (s++)->fn = code + writetoexecdiff;
             code = codeSnippet(
                 code, functionOffset++, vtableOffset,
-                bridges::cpp_uno::shared::isSimpleType(
+                !ppc64::return_in_hidden_param(
                     reinterpret_cast<
                     typelib_InterfaceAttributeTypeDescription * >(
                         member)->pAttributeTypeRef));
@@ -729,7 +752,7 @@ unsigned char * bridges::cpp_uno::shared
             (s++)->fn = code + writetoexecdiff;
             code = codeSnippet(
                 code, functionOffset++, vtableOffset,
-                bridges::cpp_uno::shared::isSimpleType(
+                !ppc64::return_in_hidden_param(
                     reinterpret_cast<
                     typelib_InterfaceMethodTypeDescription * >(
                         member)->pReturnTypeRef));
