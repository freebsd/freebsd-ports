--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/except.cxx.orig	2014-09-19 17:51:13 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/except.cxx
@@ -24,9 +24,9 @@
 // MARKER(update_precomp.py): autogen include statement, do not remove
 #include "precompiled_bridges.hxx"
 
-#if ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 6))
+#include <cstddef>
 #include <exception>
-#endif
+#include <typeinfo>
 
 #include <stdio.h>
 #include <string.h>
@@ -182,7 +182,12 @@ type_info * RTTI::getRTTI( typelib_Compo
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
@@ -196,7 +201,10 @@ type_info * RTTI::getRTTI( typelib_Compo
                     // this class has no base class
                     rtti = new __class_type_info( strdup( rttiName ) );
                 }
-                
+#else /* __GLIBCXX__ */
+                rtti = NULL;
+#endif /* __GLIBCXX__ */
+
                 pair< t_rtti_map::iterator, bool > insertion(
                     m_generatedRttis.insert( t_rtti_map::value_type( unoName, rtti ) ) );
                 OSL_ENSURE( insertion.second, "### inserting new generated rtti failed?!" );
