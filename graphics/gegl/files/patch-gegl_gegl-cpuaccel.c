--- gegl/gegl-cpuaccel.c.orig	2022-07-07 02:35:48 UTC
+++ gegl/gegl-cpuaccel.c
@@ -552,32 +552,18 @@ arch_accel (void)
 #include <fcntl.h>
 #include <string.h>
 #include <elf.h>
+#include <sys/auxv.h>
 
 #define HAVE_ACCEL 1
 
 static guint32
 arch_accel (void)
 {
-  /* TODO : add or hardcode the other ways it can be on arm, where
-   *        this info comes from the system and not from running cpu
-   *        instructions
-   */
-  int has_neon = 0;
-  int fd = open ("/proc/self/auxv", O_RDONLY);
-  Elf32_auxv_t auxv;
-  if (fd >= 0)
-  {
-    while (read (fd, &auxv, sizeof (Elf32_auxv_t)) == sizeof (Elf32_auxv_t))
-    {
-      if (auxv.a_type == AT_HWCAP)
-      {
-        if (auxv.a_un.a_val & 4096)
-          has_neon = 1;
-      }
-    }
-    close (fd);
-  }
-  return has_neon?GEGL_CPU_ACCEL_ARM_NEON:0;
+	unsigned long hwcap = 0;
+
+	elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+
+	return hwcap & HWCAP_NEON ? GEGL_CPU_ACCEL_ARM_NEON : 0;
 }
 
 #endif /* ARCH_ARM  */
