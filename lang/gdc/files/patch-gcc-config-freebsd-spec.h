--- gcc/config/freebsd-spec.h.orig	2007-11-04 23:09:45.000000000 +0300
+++ gcc/config/freebsd-spec.h	2008-08-07 05:10:48.000000000 +0400
@@ -164,3 +164,7 @@
 #else
 #define FBSD_DYNAMIC_LINKER "/libexec/ld-elf.so.1"
 #endif
+
+#if defined(HAVE_LD_EH_FRAME_HDR)
+#define LINK_EH_SPEC "%{!static:--eh-frame-hdr} "
+#endif
