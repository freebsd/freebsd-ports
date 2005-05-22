Issutracker : #i49680#
CWS         : N/A
Author      : NAKATA Maho <maho@openoffice.org> (JCA)
Description : catch up recent version of cpp_uno

--- bridges/source/cpp_uno/gcc3_freebsd_intel/cpp2uno.cxx	Wed Jan 19 00:06:09 2005
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/cpp2uno.cxx	Mon Feb 21 21:13:28 2005
@@ -77,7 +77,7 @@
 {
 
 //==================================================================================================
-static typelib_TypeClass cpp2uno_call(
+void cpp2uno_call(
 	bridges::cpp_uno::shared::CppInterfaceProxy * pThis,
 	const typelib_TypeDescription * pMemberTypeDescr,
 	typelib_TypeDescriptionReference * pReturnTypeRef, // 0 indicates void return
@@ -209,8 +209,6 @@
 		CPPU_CURRENT_NAMESPACE::raiseException(
             &aUnoExc, pThis->getBridge()->getUno2Cpp() );
             // has to destruct the any
-		// is here for dummy
-		return typelib_TypeClass_VOID;
 	}
 	else // else no exception occured...
 	{
@@ -247,22 +245,16 @@
 		}
 		if (pReturnTypeDescr)
 		{
-			typelib_TypeClass eRet = (typelib_TypeClass)pReturnTypeDescr->eTypeClass;
 			TYPELIB_DANGER_RELEASE( pReturnTypeDescr );
-			return eRet;
 		}
-		else
-			return typelib_TypeClass_VOID;
 	}
 }
 
 
 //==================================================================================================
-static typelib_TypeClass cpp_mediate(
-	sal_Int32 nFunctionIndex,
-    sal_Int32 nVtableOffset,
-	void ** pCallStack,
-	sal_Int64 * pRegisterReturn /* space for register return */ )
+extern "C" void cpp_vtable_call(
+    int nFunctionIndex, int nVtableOffset, void** pCallStack,
+    sal_Int64 nRegReturn )
 {
 	OSL_ENSURE( sizeof(sal_Int32)==sizeof(void *), "### unexpected!" );
 	
@@ -298,7 +290,6 @@
 
 	TypeDescription aMemberDescr( pTypeDescr->ppAllMembers[nMemberPos] );
     
-	typelib_TypeClass eRet;
 	switch (aMemberDescr.get()->eTypeClass)
 	{
 	case typelib_TypeClass_INTERFACE_ATTRIBUTE:
@@ -306,11 +297,11 @@
 		if (pTypeDescr->pMapMemberIndexToFunctionIndex[nMemberPos] == nFunctionIndex)
 		{
 			// is GET method
-			eRet = cpp2uno_call(
+			cpp2uno_call(
 				pCppI, aMemberDescr.get(),
 				((typelib_InterfaceAttributeTypeDescription *)aMemberDescr.get())->pAttributeTypeRef,
 				0, 0, // no params
-				pCallStack, pRegisterReturn );
+				pCallStack, &nRegReturn );
 		}
 		else
 		{
@@ -321,11 +312,11 @@
 			aParam.bIn		= sal_True;
 			aParam.bOut		= sal_False;
 			
-			eRet = cpp2uno_call(
+			cpp2uno_call(
 				pCppI, aMemberDescr.get(),
 				0, // indicates void return
 				1, &aParam,
-				pCallStack, pRegisterReturn );
+				pCallStack, &nRegReturn );
 		}
 		break;
 	}
@@ -336,11 +327,9 @@
 		{
 		case 1: // acquire()
 			pCppI->acquireProxy(); // non virtual call!
-			eRet = typelib_TypeClass_VOID;
 			break;
 		case 2: // release()
 			pCppI->releaseProxy(); // non virtual call!
-			eRet = typelib_TypeClass_VOID;
 			break;
 		case 0: // queryInterface() opt
 		{
@@ -361,20 +350,19 @@
                         &pInterface, pTD, cpp_acquire );
                     pInterface->release();
                     TYPELIB_DANGER_RELEASE( pTD );
-                    *(void **)pRegisterReturn = pCallStack[1];
-                    eRet = typelib_TypeClass_ANY;
+                    *(void **)&nRegReturn = pCallStack[1];
                     break;
                 }
                 TYPELIB_DANGER_RELEASE( pTD );
             }
 		} // else perform queryInterface()
 		default:
-			eRet = cpp2uno_call(
+			cpp2uno_call(
 				pCppI, aMemberDescr.get(),
 				((typelib_InterfaceMethodTypeDescription *)aMemberDescr.get())->pReturnTypeRef,
 				((typelib_InterfaceMethodTypeDescription *)aMemberDescr.get())->nParams,
 				((typelib_InterfaceMethodTypeDescription *)aMemberDescr.get())->pParams,
-				pCallStack, pRegisterReturn );
+				pCallStack, &nRegReturn );
 		}
 		break;
 	}
@@ -383,72 +371,55 @@
 		throw RuntimeException(
             rtl::OUString::createFromAscii("no member description found!"),
             (XInterface *)pThis );
-		// is here for dummy
-		eRet = typelib_TypeClass_VOID;
 	}
 	}
-
-	return eRet;
 }
 
 //==================================================================================================
-/**
- * is called on incoming vtable calls
- * (called by asm snippets)
- */
-static void cpp_vtable_call(
-    int nFunctionIndex, int nVtableOffset, void** pCallStack )
-    __attribute__((regparm(3)));
-
-void cpp_vtable_call( int nFunctionIndex, int nVtableOffset, void** pCallStack )
-{
-	volatile long nRegReturn[2];
-	typelib_TypeClass aType = cpp_mediate(
-        nFunctionIndex, nVtableOffset, pCallStack, (sal_Int64*)nRegReturn );
-    
-	switch( aType )
-	{
-		case typelib_TypeClass_HYPER:
-		case typelib_TypeClass_UNSIGNED_HYPER:
-			__asm__( "movl %1, %%edx\n\t"
-					 "movl %0, %%eax\n"
-					 : : "m"(nRegReturn[0]), "m"(nRegReturn[1]) );
-			break;
-		case typelib_TypeClass_FLOAT:
-			__asm__( "flds %0\n\t"
-					 "fstp %%st(0)\n\t"
-					 "flds %0\n"
-					 : : "m"(*(float *)nRegReturn) );
-			break;
-		case typelib_TypeClass_DOUBLE:
-			__asm__( "fldl %0\n\t"
-					 "fstp %%st(0)\n\t"
-					 "fldl %0\n"
-					 : : "m"(*(double *)nRegReturn) );
-			break;
-// 		case typelib_TypeClass_UNSIGNED_SHORT:
-// 		case typelib_TypeClass_SHORT:
-// 			__asm__( "movswl %0, %%eax\n"
-// 					 : : "m"(nRegReturn) );
-// 		break;
-		default:
-			__asm__( "movl %0, %%eax\n"
-					 : : "m"(nRegReturn[0]) );
-			break;
-	}
-}
-
+extern "C" void privateSnippetExecutorGeneral();
+extern "C" void privateSnippetExecutorVoid();
+extern "C" void privateSnippetExecutorHyper();
+extern "C" void privateSnippetExecutorFloat();
+extern "C" void privateSnippetExecutorDouble();
+extern "C" void privateSnippetExecutorClass();
+extern "C" typedef void (*PrivateSnippetExecutor)();
 
-//==================================================================================================
-int const codeSnippetSize = 20;
+int const codeSnippetSize = 16;
 
 unsigned char * codeSnippet(
     unsigned char * code, sal_Int32 functionIndex, sal_Int32 vtableOffset,
-    bool simpleRetType)
+    typelib_TypeClass returnTypeClass)
 {
-    if (!simpleRetType) {
+    if (!bridges::cpp_uno::shared::isSimpleType(returnTypeClass)) {
         functionIndex |= 0x80000000;
     }
+    PrivateSnippetExecutor exec;
+    switch (returnTypeClass) {
+    case typelib_TypeClass_VOID:
+        exec = privateSnippetExecutorVoid;
+        break;
+    case typelib_TypeClass_HYPER:
+    case typelib_TypeClass_UNSIGNED_HYPER:
+        exec = privateSnippetExecutorHyper;
+        break;
+    case typelib_TypeClass_FLOAT:
+        exec = privateSnippetExecutorFloat;
+        break;
+    case typelib_TypeClass_DOUBLE:
+        exec = privateSnippetExecutorDouble;
+        break;
+    case typelib_TypeClass_STRING:
+    case typelib_TypeClass_TYPE:
+    case typelib_TypeClass_ANY:
+    case typelib_TypeClass_SEQUENCE:
+    case typelib_TypeClass_STRUCT:
+    case typelib_TypeClass_INTERFACE:
+        exec = privateSnippetExecutorClass;
+        break;
+    default:
+        exec = privateSnippetExecutorGeneral;
+        break;
+    }
     unsigned char * p = code;
     OSL_ASSERT(sizeof (sal_Int32) == 4);
     // mov function_index, %eax:
@@ -459,13 +430,10 @@
     *p++ = 0xBA;
     *reinterpret_cast< sal_Int32 * >(p) = vtableOffset;
     p += sizeof (sal_Int32);
-    // mov %esp, %ecx:
-    *p++ = 0x89;
-    *p++ = 0xE1;
-    // jmp cpp_vtable_call:
+    // jmp privateSnippetExecutor:
     *p++ = 0xE9;
     *reinterpret_cast< sal_Int32 * >(p)
-        = ((unsigned char *) cpp_vtable_call) - p - sizeof (sal_Int32);
+        = ((unsigned char *) exec) - p - sizeof (sal_Int32);
     p += sizeof (sal_Int32);
     OSL_ASSERT(p - code <= codeSnippetSize);
     return code + codeSnippetSize;
@@ -504,17 +472,17 @@
             *slots++ = code;
             code = codeSnippet(
                 code, functionOffset++, vtableOffset,
-                bridges::cpp_uno::shared::isSimpleType(
-                    reinterpret_cast<
-                    typelib_InterfaceAttributeTypeDescription * >(
-                        member)->pAttributeTypeRef));
+                reinterpret_cast< typelib_InterfaceAttributeTypeDescription * >(
+                    member)->pAttributeTypeRef->eTypeClass);
             // Setter:
             if (!reinterpret_cast<
                 typelib_InterfaceAttributeTypeDescription * >(
                     member)->bReadOnly)
             {
                 *slots++ = code;
-                code = codeSnippet(code, functionOffset++, vtableOffset, true);
+                code = codeSnippet(
+                    code, functionOffset++, vtableOffset,
+                    typelib_TypeClass_VOID);
             }
             break;
 
@@ -522,10 +490,8 @@
             *slots++ = code;
             code = codeSnippet(
                 code, functionOffset++, vtableOffset,
-                bridges::cpp_uno::shared::isSimpleType(
-                    reinterpret_cast<
-                    typelib_InterfaceMethodTypeDescription * >(
-                        member)->pReturnTypeRef));
+                reinterpret_cast< typelib_InterfaceMethodTypeDescription * >(
+                    member)->pReturnTypeRef->eTypeClass);
             break;
 
         default:
