--- bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx.orig	2019-09-17 22:55:10 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/except.cxx
@@ -220,6 +220,12 @@ static void deleteException( void * pExc )
 static void deleteException( void * pExc )
 {
     __cxa_exception const * header = ((__cxa_exception const *)pExc - 1);
+    if (header->exceptionDestructor != &deleteException) {
+        // _Unwind_Exception was made __aligned__ which
+        // increased its size by 12 bytes
+        header = reinterpret_cast<__cxa_exception const *>(
+            reinterpret_cast<char const *>( header ) - 12 );
+    }
     typelib_TypeDescription * pTD = 0;
     OUString unoName( toUNOname( header->exceptionType->name() ) );
     ::typelib_typedescription_getByName( &pTD, unoName.pData );
