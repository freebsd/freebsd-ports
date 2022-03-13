--- bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx.orig	2022-01-26 14:35:29 UTC
+++ bridges/source/cpp_uno/gcc3_linux_x86-64/except.cxx
@@ -82,7 +82,7 @@ static void _GLIBCXX_CDTOR_CALLABI deleteException( vo
 static void _GLIBCXX_CDTOR_CALLABI deleteException( void * pExc )
 {
     __cxxabiv1::__cxa_exception const * header = static_cast<__cxxabiv1::__cxa_exception const *>(pExc) - 1;
-#if defined _LIBCPPABI_VERSION // detect libc++abi
+#if 1
     // First, the libcxxabi commit
     // <http://llvm.org/viewvc/llvm-project?view=revision&revision=303175>
     // "[libcxxabi] Align unwindHeader on a double-word boundary" towards
