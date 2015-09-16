--- bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx.orig	2014-02-25 08:29:00 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx
@@ -24,7 +24,12 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
+#include <cstddef>
+#include <exception>
+#include <typeinfo>
+
 #include <stdio.h>
+#include <string.h>
 #include <dlfcn.h>
 #include <cxxabi.h>
 #include <hash_map>
@@ -177,7 +182,12 @@ type_info * RTTI::getRTTI( typelib_Compo
                 char const * rttiName = symName.getStr() +4;
 #if OSL_DEBUG_LEVEL > 1
                 fprintf( stderr,"generated rtti for %s\n", rttiName );
+#ifndef __GLIBCXX__ /* #i124421# */
+                const OString aCUnoName = OUStringToOString( unoName, RTL_TEXTENCODING_UTF8);
+                OSL_TRACE( "TypeInfo for \"%s\" not found and cannot be generated.\n", aCUnoName.getStr());
+#endif /* __GLIBCXX__ */
 #endif
+#ifdef __GLIBCXX__ /* #i124421# */
                 if (pTypeDescr->pBaseTypeDescription)
                 {
                     // ensure availability of base
@@ -191,6 +201,9 @@ type_info * RTTI::getRTTI( typelib_Compo
                     // this class has no base class
                     rtti = new __class_type_info( strdup( rttiName ) );
                 }
+#else /* __GLIBCXX__ */
+                rtti = NULL;
+#endif /* __GLIBCXX__ */
 
                 pair< t_rtti_map::iterator, bool > insertion(
                     m_generatedRttis.insert( t_rtti_map::value_type( unoName, rtti ) ) );
@@ -233,7 +246,7 @@ void raiseException( uno_Any * pUnoExc, 
         OUStringToOString(
             *reinterpret_cast< OUString const * >( &pUnoExc->pType->pTypeName ),
             RTL_TEXTENCODING_ASCII_US ) );
-    fprintf( stderr, "> uno exception occured: %s\n", cstr.getStr() );
+    fprintf( stderr, "> uno exception occurred: %s\n", cstr.getStr() );
 #endif
     void * pCppExc;
     type_info * rtti;
@@ -307,7 +320,7 @@ void fillUnoException( __cxa_exception *
     OUString unoName( toUNOname( header->exceptionType->name() ) );
 #if OSL_DEBUG_LEVEL > 1
     OString cstr_unoName( OUStringToOString( unoName, RTL_TEXTENCODING_ASCII_US ) );
-    fprintf( stderr, "> c++ exception occured: %s\n", cstr_unoName.getStr() );
+    fprintf( stderr, "> c++ exception occurred: %s\n", cstr_unoName.getStr() );
 #endif
 	typelib_typedescription_getByName( &pExcTypeDescr, unoName.pData );
     if (0 == pExcTypeDescr)
