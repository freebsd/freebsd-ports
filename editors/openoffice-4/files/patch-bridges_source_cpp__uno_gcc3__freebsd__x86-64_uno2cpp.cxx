--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/uno2cpp.cxx.orig	2014-02-25 08:29:00 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/uno2cpp.cxx
@@ -24,9 +24,10 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
-#include <exception>
 #include <typeinfo>
-#include <stdio.h>
+#include <exception>
+#include <cstddef>
+#include <cxxabi.h>
 #include <stdlib.h>
 #include <string.h>
 
@@ -47,6 +48,11 @@
 
 using namespace ::rtl;
 using namespace ::com::sun::star::uno;
+#ifdef __GLIBCXX__
+using CPPU_CURRENT_NAMESPACE::__cxa_get_globals;
+#else
+using __cxxabiv1::__cxa_get_globals;
+#endif
 
 //==================================================================================================
 static void callVirtualMethod(void * pThis, sal_uInt32 nVtableIndex,
@@ -407,7 +413,7 @@ static void cpp_call(
                 Reference< XInterface >());
         }
 
-		// NO exception occured...
+		// NO exception occurred...
 		*ppUnoExc = 0;
 		
 		// reconvert temporary params
@@ -446,7 +452,7 @@ static void cpp_call(
  	catch (...)
  	{
   		// fill uno exception
-		fillUnoException( CPPU_CURRENT_NAMESPACE::__cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
+		CPPU_CURRENT_NAMESPACE::fillUnoException( __cxa_get_globals()->caughtExceptions, *ppUnoExc, pThis->getBridge()->getCpp2Uno() );
         
 		// temporary params
 		for ( ; nTempIndizes--; )
