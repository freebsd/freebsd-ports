--- bridges/source/cpp_uno/gcc3_linux_intel/except.cxx.orig	2022-03-23 13:32:00 UTC
+++ bridges/source/cpp_uno/gcc3_linux_intel/except.cxx
@@ -202,9 +202,15 @@ static void _GLIBCXX_CDTOR_CALLABI deleteException( vo
 extern "C" {
 static void _GLIBCXX_CDTOR_CALLABI deleteException( void * pExc )
 {
-    __cxa_exception const * header = static_cast<__cxa_exception const *>(pExc) - 1;
+    __cxxabiv1::__cxa_exception * header =
+        reinterpret_cast<__cxxabiv1::__cxa_exception *>(pExc);
+    if (header[-1].exceptionDestructor != &deleteException) {
+        header = reinterpret_cast<__cxxabiv1::__cxa_exception *>(
+            reinterpret_cast<char *>(header) - 12);
+    }
+    assert(header[-1].exceptionDestructor == &deleteException);
     typelib_TypeDescription * pTD = nullptr;
-    OUString unoName( toUNOname( header->exceptionType->name() ) );
+    OUString unoName( toUNOname( header[-1].exceptionType->name() ) );
     ::typelib_typedescription_getByName( &pTD, unoName.pData );
     assert(pTD && "### unknown exception type! leaving out destruction => leaking!!!");
     if (pTD)
@@ -262,8 +268,23 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
 
 void fillUnoException(uno_Any * pUnoExc, uno_Mapping * pCpp2Uno)
 {
-    __cxa_exception * header = reinterpret_cast<CPPU_CURRENT_NAMESPACE::__cxa_eh_globals*>(
-                 __cxxabiv1::__cxa_get_globals())->caughtExceptions;
+    __cxxabiv1::__cxa_exception * header =
+        reinterpret_cast<__cxxabiv1::__cxa_exception *>(
+             __cxxabiv1::__cxa_current_primary_exception());
+    if (header) {
+        __cxxabiv1::__cxa_decrement_exception_refcount(header);
+        uint64_t exc_class = header[-1].unwindHeader.exception_class
+                           & 0xffffffffffffff00;
+        if (exc_class != /* "GNUCC++" */ 0x474e5543432b2b00) {
+            header = reinterpret_cast<__cxxabiv1::__cxa_exception *>(
+                reinterpret_cast<char *>(header) - 12);
+            exc_class = header[-1].unwindHeader.exception_class
+                      & 0xffffffffffffff00;
+            if (exc_class != /* "GNUCC++" */ 0x474e5543432b2b00) {
+                header = nullptr;
+            }
+        }
+    }
     if (! header)
     {
         RuntimeException aRE( "no exception header!" );
@@ -273,7 +294,7 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
         return;
     }
 
-    std::type_info *exceptionType = __cxxabiv1::__cxa_current_exception_type();
+    std::type_info *exceptionType = header[-1].exceptionType;
 
     typelib_TypeDescription * pExcTypeDescr = nullptr;
     OUString unoName( toUNOname( exceptionType->name() ) );
@@ -292,7 +313,7 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
     else
     {
         // construct uno exception any
-        uno_any_constructAndConvert( pUnoExc, header->adjustedPtr, pExcTypeDescr, pCpp2Uno );
+        uno_any_constructAndConvert( pUnoExc, header[-1].adjustedPtr, pExcTypeDescr, pCpp2Uno );
         typelib_typedescription_release( pExcTypeDescr );
     }
 }
