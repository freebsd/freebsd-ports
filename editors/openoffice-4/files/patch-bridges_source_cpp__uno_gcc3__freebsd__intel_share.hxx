--- bridges/source/cpp_uno/gcc3_freebsd_intel/share.hxx.orig	2020-10-06 14:16:16 UTC
+++ bridges/source/cpp_uno/gcc3_freebsd_intel/share.hxx
@@ -62,7 +62,7 @@ extern "C" void *__cxa_allocate_exception(
 #endif /* __GLIBCXX__ */
 
 extern "C" void *__cxa_allocate_exception(
-    std::size_t thrown_size ) throw();
+    size_t thrown_size );
 extern "C" void __cxa_throw (
     void *thrown_exception, std::type_info *tinfo, void (*dest) (void *) ) __attribute__((noreturn));
 
