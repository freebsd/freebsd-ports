--- src/util.cpp.orig	2026-02-04 04:33:16 UTC
+++ src/util.cpp
@@ -44,7 +44,7 @@
 #include <llvm/Support/Path.h>
 
 #if ISPC_LLVM_VERSION < ISPC_LLVM_21_0
-#ifdef _LIBCPP_VERSION
+#if defined(ISPC_HOST_IS_APPLE) && defined(_LIBCPP_VERSION)
 // Provide own definition of std::__libcpp_verbose_abort to avoid missing symbols error on macOS with old
 // system libc++.1.dylib. The symbol is there for macOS 13 Ventura and later, but not macOS 12 and earlier.
 // See #3071 for more details.
@@ -60,7 +60,7 @@ void std::__libcpp_verbose_abort(char const *format, .
 
     abort();
 }
-#endif // _LIBCPP_VERSION
+#endif // ISPC_HOST_IS_APPLE && _LIBCPP_VERSION
 #endif // ISPC_LLVM_VERSION < ISPC_LLVM_21_0
 
 using namespace ispc;
