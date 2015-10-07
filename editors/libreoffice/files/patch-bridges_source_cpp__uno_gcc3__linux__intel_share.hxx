--- bridges/source/cpp_uno/gcc3_linux_intel/share.hxx.orig	2015-08-22 06:41:35 UTC
+++ bridges/source/cpp_uno/gcc3_linux_intel/share.hxx
@@ -32,10 +32,34 @@
 #include <uno/any2.h>
 #include "uno/mapping.h"
 
-namespace CPPU_CURRENT_NAMESPACE
+#ifdef _LIBCPP_VERSION
+
+namespace __cxxabiv1
 {
+    struct __class_type_info : public std::type_info
+    {
+        explicit __class_type_info( const char *__n ) : type_info( __n ) { }
+        virtual ~__class_type_info();
+    };
 
-void dummy_can_throw_anything( char const * );
+    struct __si_class_type_info : public __class_type_info
+    {
+        explicit __si_class_type_info( const char *__n, const __class_type_info *__b ) :
+            __class_type_info( __n ), __base_type( __b ) { }
+        virtual ~__si_class_type_info();
+        const __class_type_info *__base_type;
+    };
+
+extern "C" void *__cxa_allocate_exception( std::size_t thrown_size ) _NOEXCEPT;
+
+extern "C" _LIBCPP_NORETURN void __cxa_throw(
+    void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) );
+}
+
+#else
+
+namespace CPPU_CURRENT_NAMESPACE
+{
 
 // ----- following decl from libstdc++-v3/libsupc++/unwind-cxx.h and unwind.h
 
@@ -104,6 +128,8 @@ extern "C" void __cxa_throw(
     __attribute__((noreturn));
 }
 #endif
+}
+#endif
 
 extern "C" void privateSnippetExecutorGeneral();
 extern "C" void privateSnippetExecutorVoid();
@@ -115,12 +141,17 @@ extern "C" void privateSnippetExecutorCl
 namespace CPPU_CURRENT_NAMESPACE
 {
 
+void dummy_can_throw_anything( char const * );
+
 void raiseException(
     uno_Any * pUnoExc, uno_Mapping * pUno2Cpp );
 
 void fillUnoException(
+#ifdef _LIBCPP_VERSION
+    __cxxabiv1::__cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
+#else
     __cxa_exception * header, uno_Any *, uno_Mapping * pCpp2Uno );
-
+#endif
 }
 
 namespace x86
