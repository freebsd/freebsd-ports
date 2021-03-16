--- src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp.orig	2021-03-15 13:24:28 UTC
+++ src/jdk.hotspot.agent/bsd/native/libsaproc/BsdDebuggerLocal.cpp
@@ -42,7 +42,7 @@
 #include "sun_jvm_hotspot_debugger_sparc_SPARCThreadContext.h"
 #endif
 
-#ifdef ppc64
+#if defined(ppc64) || defined(ppc64le)
 #include "sun_jvm_hotspot_debugger_ppc64_PPC64ThreadContext.h"
 #endif
 
@@ -326,7 +326,7 @@ JNIEXPORT jlongArray JNICALL Java_sun_jvm_hotspot_debu
 #if defined(sparc) || defined(sparcv9)
 #define NPRGREG sun_jvm_hotspot_debugger_sparc_SPARCThreadContext_NPRGREG
 #endif
-#ifdef ppc64
+#if defined(ppc64) || defined(ppc64le)
 #define NPRGREG sun_jvm_hotspot_debugger_ppc64_PPC64ThreadContext_NPRGREG
 #endif
 #ifdef aarch64
