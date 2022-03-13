--- bridges/source/cpp_uno/gcc3_linux_aarch64/abi.cxx.orig	2022-01-26 14:35:29 UTC
+++ bridges/source/cpp_uno/gcc3_linux_aarch64/abi.cxx
@@ -147,7 +147,7 @@ extern "C" void _GLIBCXX_CDTOR_CALLABI deleteException
 extern "C" void _GLIBCXX_CDTOR_CALLABI deleteException(void * exception) {
     __cxxabiv1::__cxa_exception * header =
         static_cast<__cxxabiv1::__cxa_exception *>(exception) - 1;
-#if !defined MACOSX && defined _LIBCPPABI_VERSION // detect libc++abi
+#if 1
     // First, the libcxxabi commit
     // <http://llvm.org/viewvc/llvm-project?view=revision&revision=303175>
     // "[libcxxabi] Align unwindHeader on a double-word boundary" towards
