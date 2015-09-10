--- bridges/source/cpp_uno/gcc3_linux_x86-64/rtti.cxx.orig	2015-08-22 06:41:35 UTC
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/rtti.cxx
@@ -57,11 +57,7 @@ public:
 };
 
 RTTI::RTTI()
-#if defined(FREEBSD) && __FreeBSD_version < 702104
-    : m_hApp( dlopen( 0, RTLD_NOW | RTLD_GLOBAL ) )
-#else
     : m_hApp( dlopen( 0, RTLD_LAZY ) )
-#endif
 {
 }
 
@@ -95,11 +91,7 @@ std::type_info * RTTI::getRTTI(typelib_T
         buf.append( 'E' );
 
         OString symName( buf.makeStringAndClear() );
-#if defined(FREEBSD) && __FreeBSD_version < 702104 /* #i22253# */
-        rtti = (std::type_info *)dlsym( RTLD_DEFAULT, symName.getStr() );
-#else
         rtti = static_cast<std::type_info *>(dlsym( m_hApp, symName.getStr() ));
-#endif
 
         if (rtti)
         {
@@ -165,6 +157,9 @@ std::type_info * RTTI::getRTTI(typelib_T
                             break;
                         default:
                             {
+#ifdef _LIBCPP_VERSION
+                                //TODO
+#else
                                 char * pad = new char[
                                     sizeof (__cxxabiv1::__vmi_class_type_info)
                                     + ((itd.nBaseTypes - 1)
@@ -187,6 +182,7 @@ std::type_info * RTTI::getRTTI(typelib_T
                                            | ((8 * i) << __cxxabiv1::__base_class_type_info::__offset_shift));
                                 }
                                 rtti = info;
+#endif
                                 break;
                             }
                         }
