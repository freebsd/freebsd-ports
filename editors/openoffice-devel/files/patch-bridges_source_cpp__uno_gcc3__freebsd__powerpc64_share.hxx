--- bridges/source/cpp_uno/gcc3_freebsd_powerpc64/share.hxx.orig	2019-09-17 22:55:10 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc64/share.hxx
@@ -35,6 +35,7 @@ namespace CPPU_CURRENT_NAMESPACE
 
 // ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
 
+#ifdef __GLIBCXX__
 struct _Unwind_Exception
 {
     unsigned exception_class __attribute__((__mode__(__DI__)));
@@ -63,18 +64,21 @@ struct __cxa_exception
     
     _Unwind_Exception unwindHeader;
 };    
+#endif /* __GLIBCXX__ */
 
 extern "C" void *__cxa_allocate_exception(
-    std::size_t thrown_size ) throw();
+    size_t thrown_size );
 extern "C" void __cxa_throw (
     void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
 
+#ifdef __GLIBCXX__
 struct __cxa_eh_globals
 {
     __cxa_exception *caughtExceptions;
     unsigned int uncaughtExceptions;
 };
 extern "C" __cxa_eh_globals *__cxa_get_globals () throw();
+#endif /* __GLIBCXX__ */
 
 // -----
 
@@ -82,6 +86,10 @@ void raiseException(
 void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
 //==================================================================================================
+#ifndef __GLIBCXX__
+using __cxxabiv1:: __cxa_exception;
+#endif /* __GLIBCXX__ */
+
 void fillUnoException(
     __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
 }
