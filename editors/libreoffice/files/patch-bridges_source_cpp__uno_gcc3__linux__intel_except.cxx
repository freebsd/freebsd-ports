--- bridges/source/cpp_uno/gcc3_linux_intel/except.cxx.orig	2015-08-22 06:41:35 UTC
+++ bridges/source/cpp_uno/gcc3_linux_intel/except.cxx
@@ -100,11 +100,7 @@
 };
 
 RTTI::RTTI()
-#if defined(FREEBSD) && __FreeBSD_version < 702104
-    : m_hApp( dlopen( 0, RTLD_NOW | RTLD_GLOBAL ) )
-#else
     : m_hApp( dlopen( 0, RTLD_LAZY ) )
-#endif
 {
 }
 
@@ -139,11 +135,7 @@
         buf.append( 'E' );
 
         OString symName( buf.makeStringAndClear() );
-#if defined(FREEBSD) && __FreeBSD_version < 702104 /* #i22253# */
-        rtti = (type_info *)dlsym( RTLD_DEFAULT, symName.getStr() );
-#else
         rtti = static_cast<type_info *>(dlsym( m_hApp, symName.getStr() ));
-#endif
 
         if (rtti)
         {
@@ -169,13 +161,13 @@
                     // ensure availability of base
                     type_info * base_rtti = getRTTI(
                         (typelib_CompoundTypeDescription *)pTypeDescr->pBaseTypeDescription );
-                    rtti = new __si_class_type_info(
-                        strdup( rttiName ), static_cast<__class_type_info *>(base_rtti) );
+                    rtti = new __cxxabiv1::__si_class_type_info(
+                        strdup( rttiName ), static_cast<__cxxabiv1::__class_type_info *>(base_rtti) );
                 }
                 else
                 {
                     // this class has no base class
-                    rtti = new __class_type_info( strdup( rttiName ) );
+                    rtti = new __cxxabiv1::__class_type_info( strdup( rttiName ) );
                 }
 
                 pair< t_rtti_map::iterator, bool > insertion(
