--- bridges/source/cpp_uno/gcc3_linux_powerpc64/share.hxx.orig	2020-04-07 10:06:14.193381000 -0500
+++ bridges/source/cpp_uno/gcc3_linux_powerpc64/share.hxx	2020-04-09 11:33:30.706043000 -0500
@@ -25,6 +25,63 @@
 #include <exception>
 #include <cstddef>
 
+#include <cxxabi.h>
+#ifndef _GLIBCXX_CDTOR_CALLABI // new in GCC 4.7 cxxabi.h
+#define _GLIBCXX_CDTOR_CALLABI
+#endif
+#include <unwind.h>
+
+#include <config_cxxabi.h>
+
+#if !HAVE_CXXABI_H_CLASS_TYPE_INFO
+// <https://mentorembedded.github.io/cxx-abi/abi.html>,
+// libstdc++-v3/libsupc++/cxxabi.h:
+namespace __cxxabiv1 {
+class __class_type_info: public std::type_info {
+public:
+    explicit __class_type_info(char const * n): type_info(n) {}
+    ~__class_type_info() override;
+};
+}
+#endif
+
+#if !HAVE_CXXABI_H_SI_CLASS_TYPE_INFO
+// <https://mentorembedded.github.io/cxx-abi/abi.html>,
+// libstdc++-v3/libsupc++/cxxabi.h:
+namespace __cxxabiv1 {
+class __si_class_type_info: public __class_type_info {
+public:
+    __class_type_info const * __base_type;
+    explicit __si_class_type_info(
+        char const * n, __class_type_info const *base):
+        __class_type_info(n), __base_type(base) {}
+    ~__si_class_type_info() override;
+};
+}
+#endif
+#if !HAVE_CXXABI_H_CXA_GET_GLOBALS
+namespace __cxxabiv1 { extern "C" void *__cxa_get_globals () throw(); }
+#endif
+#if !HAVE_CXXABI_H_CXA_CURRENT_EXCEPTION_TYPE
+namespace __cxxabiv1 {
+extern "C" std::type_info *__cxa_current_exception_type() throw();
+}
+#endif
+
+#if !HAVE_CXXABI_H_CXA_ALLOCATE_EXCEPTION
+namespace __cxxabiv1 {
+extern "C" void *__cxa_allocate_exception(
+    std::size_t thrown_size ) throw();
+}
+#endif
+
+#if !HAVE_CXXABI_H_CXA_THROW
+namespace __cxxabiv1 {
+extern "C" void __cxa_throw (
+    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
+}
+#endif
+
 namespace CPPU_CURRENT_NAMESPACE
 {
 
@@ -33,6 +90,7 @@
 
 // ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
 
+#if 0
 struct _Unwind_Exception
 {
     unsigned exception_class __attribute__((__mode__(__DI__)));
@@ -40,9 +98,11 @@
     unsigned private_1 __attribute__((__mode__(__word__)));
     unsigned private_2 __attribute__((__mode__(__word__)));
 } __attribute__((__aligned__));
+#endif
 
 struct __cxa_exception
 {
+    //uintptr_t   referenceCount;
     std::type_info *exceptionType;
     void (*exceptionDestructor)(void *);
 
@@ -62,19 +122,11 @@
     _Unwind_Exception unwindHeader;
 };
 
-extern "C" void *__cxa_allocate_exception(
-    std::size_t thrown_size ) throw();
-extern "C" void __cxa_throw (
-    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
-
 struct __cxa_eh_globals
 {
     __cxa_exception *caughtExceptions;
     unsigned int uncaughtExceptions;
 };
-
-extern "C" __cxa_eh_globals *__cxa_get_globals () throw();
-extern "C" std::type_info *__cxa_current_exception_type() throw();
 
 void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
