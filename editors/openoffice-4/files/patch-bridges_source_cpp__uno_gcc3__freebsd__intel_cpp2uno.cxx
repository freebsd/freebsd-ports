--- bridges/source/cpp_uno/gcc3_freebsd_intel/cpp2uno.cxx.orig	2014-02-25 08:29:00 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/cpp2uno.cxx
@@ -24,6 +24,11 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
+#include <typeinfo>
+#include <exception>
+#include <cstddef>
+#include <cxxabi.h>
+
 #include <com/sun/star/uno/genfunc.hxx>
 #include "com/sun/star/uno/RuntimeException.hpp"
 #include <uno/data.h>
@@ -159,7 +164,7 @@ void cpp2uno_call(
 	(*pThis->getUnoI()->pDispatcher)(
         pThis->getUnoI(), pMemberTypeDescr, pUnoReturn, pUnoArgs, &pUnoExc );
 	
-	// in case an exception occured...
+	// in case an exception occurred...
 	if (pUnoExc)
 	{
 		// destruct temporary in/inout params
@@ -178,7 +183,7 @@ void cpp2uno_call(
             &aUnoExc, pThis->getBridge()->getUno2Cpp() );
             // has to destruct the any
 	}
-	else // else no exception occured...
+	else // else no exception occurred...
 	{
 		// temporary params
 		for ( ; nTempIndizes--; )
