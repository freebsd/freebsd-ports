--- bridges/source/cpp_uno/gcc3_linux_aarch64/uno2cpp.cxx.orig	2022-03-23 13:32:00 UTC
+++ bridges/source/cpp_uno/gcc3_linux_aarch64/uno2cpp.cxx
@@ -304,8 +304,10 @@ void call(
                 "C++ code threw unknown exception");
         }
     } catch (css::uno::Exception &) {
-        __cxxabiv1::__cxa_exception * header = reinterpret_cast<__cxxabiv1::__cxa_eh_globals *>(
-            __cxxabiv1::__cxa_get_globals())->caughtExceptions;
+        __cxxabiv1::__cxa_exception * header =
+            reinterpret_cast<__cxxabiv1::__cxa_exception *>(
+                 __cxxabiv1::__cxa_current_primary_exception());
+        __cxxabiv1::__cxa_decrement_exception_refcount(header);
 #if !defined MACOSX && defined _LIBCPPABI_VERSION // detect libc++abi
         // Very bad HACK to find out whether we run against a libcxxabi that has a new
         // __cxa_exception::reserved member at the start, introduced with LLVM 10
@@ -335,8 +337,7 @@ void call(
         }
 #endif
         abi_aarch64::mapException(
-            header,
-            __cxxabiv1::__cxa_current_exception_type(), *exception,
+            header - 1, header[-1].exceptionType, *exception,
             proxy->getBridge()->getCpp2Uno());
         for (sal_Int32 i = 0; i != count; ++i) {
             if (cppArgs[i] != nullptr) {
