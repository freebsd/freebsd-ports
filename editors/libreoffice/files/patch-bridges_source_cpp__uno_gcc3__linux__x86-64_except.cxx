--- bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx.orig	2022-03-23 13:32:00 UTC
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx
@@ -193,7 +193,9 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
 
 void fillUnoException(uno_Any * pUnoExc, uno_Mapping * pCpp2Uno)
 {
-    __cxxabiv1::__cxa_exception * header = __cxxabiv1::__cxa_get_globals()->caughtExceptions;
+    __cxxabiv1::__cxa_exception * header =
+        reinterpret_cast<__cxxabiv1::__cxa_exception *>(
+             __cxxabiv1::__cxa_current_primary_exception());
     if (! header)
     {
         RuntimeException aRE( "no exception header!" );
@@ -202,6 +204,7 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
         SAL_WARN("bridges", aRE.Message);
         return;
     }
+    __cxxabiv1::__cxa_decrement_exception_refcount(header);
 
 #if defined _LIBCPPABI_VERSION // detect libc++abi
     // Very bad HACK to find out whether we run against a libcxxabi that has a new
@@ -231,7 +234,7 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
     }
 #endif
 
-    std::type_info *exceptionType = __cxxabiv1::__cxa_current_exception_type();
+    std::type_info *exceptionType = header[-1].exceptionType;
 
     typelib_TypeDescription * pExcTypeDescr = nullptr;
     OUString unoName( toUNOname( exceptionType->name() ) );
@@ -250,7 +253,7 @@ void fillUnoException(uno_Any * pUnoExc, uno_Mapping *
     else
     {
         // construct uno exception any
-        uno_any_constructAndConvert( pUnoExc, header->adjustedPtr, pExcTypeDescr, pCpp2Uno );
+        uno_any_constructAndConvert( pUnoExc, header[-1].adjustedPtr, pExcTypeDescr, pCpp2Uno );
         typelib_typedescription_release( pExcTypeDescr );
     }
 }
