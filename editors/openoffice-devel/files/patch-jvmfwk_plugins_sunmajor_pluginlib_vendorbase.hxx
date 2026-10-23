--- jvmfwk/plugins/sunmajor/pluginlib/vendorbase.hxx.orig	2026-10-21 00:00:00 UTC
+++ jvmfwk/plugins/sunmajor/pluginlib/vendorbase.hxx
@@ -44,7 +44,11 @@
 #elif defined INTEL
 #define JFW_PLUGIN_ARCH "i386"
 #elif defined POWERPC64
+#ifdef OSL_BIGENDIAN
 #define JFW_PLUGIN_ARCH "ppc64"
+#else
+#define JFW_PLUGIN_ARCH "ppc64le"
+#endif
 #elif defined POWERPC
 #define JFW_PLUGIN_ARCH "ppc"
 #elif defined MIPS
