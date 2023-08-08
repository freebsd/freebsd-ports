--- core/unix/src/TUnixSystem.cxx.orig	2022-11-16 10:35:46 UTC
+++ core/unix/src/TUnixSystem.cxx
@@ -180,7 +180,7 @@ extern "C" {
 #   endif
 #   define HAVE_DLADDR
 #endif
-#if defined(R__MACOSX)
+#if defined(R__MACOSX) || defined(R__FBSD)
 #      define HAVE_BACKTRACE_SYMBOLS_FD
 #      define HAVE_DLADDR
 #endif
