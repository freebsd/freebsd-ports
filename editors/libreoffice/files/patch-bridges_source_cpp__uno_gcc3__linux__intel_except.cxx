Fix uno bridge exception handling on i386.  This matches the amd64
implementation and fixes a segfault in code that uses uno exceptions.

--- bridges/source/cpp_uno/gcc3_linux_intel/except.cxx.orig	2019-03-13 18:20:48.089705000 +0000
+++ bridges/source/cpp_uno/gcc3_linux_intel/except.cxx	2019-03-13 18:21:05.979965000 +0000
@@ -196,7 +196,7 @@
 extern "C" {
 static void _GLIBCXX_CDTOR_CALLABI deleteException( void * pExc )
 {
-    __cxa_exception const * header = static_cast<__cxa_exception const *>(pExc) - 1;
+    __cxxabiv1::__cxa_exception const * header = (static_cast<__cxxabiv1::__cxa_exception const *>(pExc) - 1);
     typelib_TypeDescription * pTD = nullptr;
     OUString unoName( toUNOname( header->exceptionType->name() ) );
     ::typelib_typedescription_getByName( &pTD, unoName.pData );
