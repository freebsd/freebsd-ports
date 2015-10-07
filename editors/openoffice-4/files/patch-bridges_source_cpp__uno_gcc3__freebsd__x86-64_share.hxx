--- bridges/source/cpp_uno/gcc3_freebsd_x86-64/share.hxx.orig	2014-02-25 08:28:59 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_x86-64/share.hxx
@@ -23,10 +23,6 @@
 
 #include "uno/mapping.h"
 
-#include <typeinfo>
-#include <exception>
-#include <cstddef>
-
 namespace CPPU_CURRENT_NAMESPACE
 {
 
@@ -34,6 +30,7 @@ void dummy_can_throw_anything( char cons
 
 // ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
 
+#ifdef __GLIBCXX__
 struct _Unwind_Exception
 {
     unsigned exception_class __attribute__((__mode__(__DI__)));
@@ -62,18 +59,21 @@ struct __cxa_exception
     
     _Unwind_Exception unwindHeader;
 };    
+#endif /* __GLIBCXX__ */
 
 extern "C" void *__cxa_allocate_exception(
     std::size_t thrown_size ) throw();
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
 
@@ -81,6 +81,10 @@ extern "C" __cxa_eh_globals *__cxa_get_g
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
