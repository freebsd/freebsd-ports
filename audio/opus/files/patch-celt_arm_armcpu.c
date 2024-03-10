--- celt/arm/armcpu.c.orig	2024-03-01 07:55:09 UTC
+++ celt/arm/armcpu.c
@@ -191,6 +191,54 @@ opus_uint32 opus_cpu_capabilities(void)
   return flags;
 }
 
+#elif defined(__FreeBSD__)
+#include <sys/auxv.h>
+
+opus_uint32 opus_cpu_capabilities(void)
+{
+  long hwcap = 0;
+  opus_uint32 flags = 0;
+
+# if defined(OPUS_ARM_MAY_HAVE_MEDIA) \
+ || defined(OPUS_ARM_MAY_HAVE_NEON) || defined(OPUS_ARM_MAY_HAVE_NEON_INTR)
+  /* FreeBSD required armv6+, always supported media instructions */
+  flags |= OPUS_CPU_ARM_MEDIA_FLAG;
+# endif
+
+  elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+
+# if defined(OPUS_ARM_MAY_HAVE_EDSP) || defined(OPUS_ARM_MAY_HAVE_MEDIA) \
+ || defined(OPUS_ARM_MAY_HAVE_NEON) || defined(OPUS_ARM_MAY_HAVE_NEON_INTR)
+#  ifdef HWCAP_EDSP
+  if (hwcap & HWCAP_EDSP)
+    flags |= OPUS_CPU_ARM_EDSP_FLAG;
+#  endif
+
+#  if defined(OPUS_ARM_MAY_HAVE_NEON) || defined(OPUS_ARM_MAY_HAVE_NEON_INTR)
+#   ifdef HWCAP_NEON
+  if (hwcap & HWCAP_NEON)
+    flags |= OPUS_CPU_ARM_NEON_FLAG;
+#   elif defined(HWCAP_ASIMD)
+  if (hwcap & HWCAP_ASIMD)
+    flags |= OPUS_CPU_ARM_NEON_FLAG | OPUS_CPU_ARM_MEDIA_FLAG | OPUS_CPU_ARM_EDSP_FLAG;
+#   endif
+#  endif
+#  if defined(OPUS_ARM_MAY_HAVE_DOTPROD) && defined(HWCAP_ASIMDDP)
+  if (hwcap & HWCAP_ASIMDDP)
+    flags |= OPUS_CPU_ARM_DOTPROD_FLAG;
+#  endif
+# endif
+
+#if defined(OPUS_ARM_PRESUME_AARCH64_NEON_INTR)
+    flags |= OPUS_CPU_ARM_EDSP_FLAG | OPUS_CPU_ARM_MEDIA_FLAG | OPUS_CPU_ARM_NEON_FLAG;
+# if defined(OPUS_ARM_PRESUME_DOTPROD)
+    flags |= OPUS_CPU_ARM_DOTPROD_FLAG;
+# endif
+#endif
+
+  return (flags);
+}
+
 #else
 /* The feature registers which can tell us what the processor supports are
  * accessible in priveleged modes only, so we can't have a general user-space
