--- src/include/libks/ks_platform.h.orig	2026-05-09 17:13:32 UTC
+++ src/include/libks/ks_platform.h
@@ -25,7 +25,7 @@ KS_BEGIN_EXTERN_C
 
 KS_BEGIN_EXTERN_C
 
-#if !defined(KS_PLAT_LIN) && !defined(KS_PLAT_WIN) && !defined(KS_PLAT_MAC)
+#if !defined(KS_PLAT_LIN) && !defined(KS_PLAT_WIN) && !defined(KS_PLAT_MAC) && !defined(KS_PLAT_FBSD)
 #ifdef __linux__
 #define KS_PLAT_LIN
 #else
@@ -34,6 +34,10 @@ KS_BEGIN_EXTERN_C
 #else
 #ifdef __APPLE__
 #define KS_PLAT_MAC
+#else
+#ifdef __FreeBSD__
+#define KS_PLAT_FBSD
+#endif
 #endif
 #endif
 #endif
