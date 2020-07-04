--- libpolyml/polyffi.cpp.orig	2017-11-18 13:45:15 UTC
+++ libpolyml/polyffi.cpp
@@ -108,9 +108,10 @@ static struct _abiTable { const char *abiName; ffi_abi
     {"ms_cdecl", FFI_MS_CDECL},
 #elif defined(X86_WIN64)
     {"win64", FFI_WIN64},
+#elif defined(X86_64) || (defined (__x86_64__) && defined (X86_DARWIN))
+    {"unix64", FFI_UNIX64},
 #elif defined(X86_ANY)
     {"sysv", FFI_SYSV},
-    {"unix64", FFI_UNIX64},
 #endif
     { "default", FFI_DEFAULT_ABI}
 };
