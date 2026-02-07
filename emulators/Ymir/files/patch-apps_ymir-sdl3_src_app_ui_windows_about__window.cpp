--- apps/ymir-sdl3/src/app/ui/windows/about_window.cpp.orig	2025-10-14 17:56:52 UTC
+++ apps/ymir-sdl3/src/app/ui/windows/about_window.cpp
@@ -48,6 +48,11 @@
 #define ZLIB_VERSION "1.3.1" // Private dependency of libchdr
 #define ZSTD_VERSION "1.5.6" // Private dependency of libchdr
 
+// Needed on 13.5, openssl in base is too old
+#ifndef OPENSSL_FULL_VERSION_STR
+#define OPENSSL_FULL_VERSION_STR OPENSSL_VERSION_TEXT
+#endif
+
 static const std::string fmtVersion = std::to_string(FMT_VERSION / 10000) + "." +
                                       std::to_string(FMT_VERSION / 100 % 100) + "." + std::to_string(FMT_VERSION % 100);
 
