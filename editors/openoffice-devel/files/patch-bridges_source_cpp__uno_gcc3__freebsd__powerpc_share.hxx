--- bridges/source/cpp_uno/gcc3_freebsd_powerpc/share.hxx.orig	2019-09-17 22:55:10 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_powerpc/share.hxx
@@ -65,7 +65,7 @@ extern "C" void *__cxa_allocate_exception(
 };    
 
 extern "C" void *__cxa_allocate_exception(
-    std::size_t thrown_size ) throw();
+    size_t thrown_size );
 extern "C" void __cxa_throw (
     void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
 
