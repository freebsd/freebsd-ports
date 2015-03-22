--- bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx.orig	2014-02-25 08:29:00 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx
@@ -24,7 +24,12 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
+#if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 6)) || defined(__clang__)
+#include <exception>
+#endif
+
 #include <stdio.h>
+#include <string.h>
 #include <dlfcn.h>
 #include <cxxabi.h>
 #include <hash_map>
@@ -233,7 +238,7 @@ void raiseException( uno_Any * pUnoExc, 
         OUStringToOString(
             *reinterpret_cast< OUString const * >( &pUnoExc->pType->pTypeName ),
             RTL_TEXTENCODING_ASCII_US ) );
-    fprintf( stderr, "> uno exception occured: %s\n", cstr.getStr() );
+    fprintf( stderr, "> uno exception occurred: %s\n", cstr.getStr() );
 #endif
     void * pCppExc;
     type_info * rtti;
@@ -307,7 +312,7 @@ void fillUnoException( __cxa_exception *
     OUString unoName( toUNOname( header->exceptionType->name() ) );
 #if OSL_DEBUG_LEVEL > 1
     OString cstr_unoName( OUStringToOString( unoName, RTL_TEXTENCODING_ASCII_US ) );
-    fprintf( stderr, "> c++ exception occured: %s\n", cstr_unoName.getStr() );
+    fprintf( stderr, "> c++ exception occurred: %s\n", cstr_unoName.getStr() );
 #endif
 	typelib_typedescription_getByName( &pExcTypeDescr, unoName.pData );
     if (0 == pExcTypeDescr)
