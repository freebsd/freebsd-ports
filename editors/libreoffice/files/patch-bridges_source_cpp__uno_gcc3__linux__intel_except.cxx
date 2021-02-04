Fix uno bridge exception handling on i386.  This matches the amd64
implementation and fixes a segfault in code that uses uno exceptions.

--- bridges/source/cpp_uno/gcc3_linux_intel/except.cxx.orig	2020-11-22 14:05:28 UTC
+++ bridges/source/cpp_uno/gcc3_linux_intel/except.cxx
@@ -202,7 +202,7 @@ type_info * RTTI::getRTTI( typelib_CompoundTypeDescrip
 extern "C" {
 static void _GLIBCXX_CDTOR_CALLABI deleteException( void * pExc )
 {
-    __cxa_exception const * header = static_cast<__cxa_exception const *>(pExc) - 1;
+    __cxxabiv1::__cxa_exception const * header = (static_cast<__cxxabiv1::__cxa_exception const *>(pExc) - 1);
     typelib_TypeDescription * pTD = nullptr;
     OUString unoName( toUNOname( header->exceptionType->name() ) );
     ::typelib_typedescription_getByName( &pTD, unoName.pData );
