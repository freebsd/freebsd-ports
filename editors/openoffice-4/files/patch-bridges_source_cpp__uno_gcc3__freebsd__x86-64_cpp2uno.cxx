--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/cpp2uno.cxx.orig	2014-02-25 08:28:59 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/cpp2uno.cxx
@@ -24,9 +24,10 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
-#include <stdio.h>
-#include <stdlib.h>
-#include <hash_map>
+#include <typeinfo>
+#include <exception>
+#include <cstddef>
+#include <cxxabi.h>
 
 #include <rtl/alloc.h>
 #include <osl/mutex.hxx>
@@ -194,7 +195,7 @@ static typelib_TypeClass cpp2uno_call(
 	// invoke uno dispatch call
 	(*pThis->getUnoI()->pDispatcher)( pThis->getUnoI(), pMemberTypeDescr, pUnoReturn, pUnoArgs, &pUnoExc );
 	
-	// in case an exception occured...
+	// in case an exception occurred...
 	if ( pUnoExc )
 	{
 		// destruct temporary in/inout params
@@ -213,7 +214,7 @@ static typelib_TypeClass cpp2uno_call(
 		// is here for dummy
 		return typelib_TypeClass_VOID;
 	}
-	else // else no exception occured...
+	else // else no exception occurred...
 	{
 		// temporary params
 		for ( ; nTempIndizes--; )
