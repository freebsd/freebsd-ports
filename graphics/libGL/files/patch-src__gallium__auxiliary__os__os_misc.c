--- src/gallium/auxiliary/os/os_misc.c.orig	2014-09-19 18:23:33 UTC
+++ src/gallium/auxiliary/os/os_misc.c
@@ -128,6 +128,8 @@ os_get_total_physical_memory(uint64_t *s
    mib[1] = HW_PHYSMEM64;
 #elif defined(PIPE_OS_FREEBSD)
    mib[1] = HW_REALMEM;
+#elif defined(PIPE_OS_DRAGONFLY)
+   mib[1] = HW_PHYSMEM;
 #else
 #error Unsupported *BSD
 #endif
