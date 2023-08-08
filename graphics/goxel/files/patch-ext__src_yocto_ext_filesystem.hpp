--- ext_src/yocto/ext/filesystem.hpp.orig	2022-08-16 08:30:35 UTC
+++ ext_src/yocto/ext/filesystem.hpp
@@ -1525,7 +1525,7 @@ GHC_INLINE std::string systemErrorText(ErrorNumber cod
     std::string msg = toUtf8(std::wstring((LPWSTR)msgBuf));
     LocalFree(msgBuf);
     return msg;
-#elif defined(GHC_OS_MACOS) || ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !defined(_GNU_SOURCE)) || (defined(GHC_OS_ANDROID) && __ANDROID_API__ < 23) || defined(EMSCRIPTEN)
+#elif defined(GHC_OS_MACOS) || ((_POSIX_C_SOURCE >= 200112L || _XOPEN_SOURCE >= 600) && !defined(_GNU_SOURCE)) || (defined(GHC_OS_ANDROID) && __ANDROID_API__ < 23) || defined(EMSCRIPTEN) || defined(__FreeBSD__)
     char buffer[512];
     int rc = strerror_r(code ? code : errno, buffer, sizeof(buffer));
     return rc == 0 ? (const char*)buffer : "Error in strerror_r!";
