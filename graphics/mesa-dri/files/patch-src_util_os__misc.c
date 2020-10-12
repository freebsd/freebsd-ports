--- src/util/os_misc.c.orig	2020-09-28 22:52:13 UTC
+++ src/util/os_misc.c
@@ -58,7 +58,7 @@
 #  include <log/log.h>
 #elif DETECT_OS_LINUX || DETECT_OS_CYGWIN || DETECT_OS_SOLARIS || DETECT_OS_HURD
 #  include <unistd.h>
-#elif DETECT_OS_OPENBSD
+#elif DETECT_OS_OPENBSD || DETECT_OS_FREEBSD
 #  include <sys/resource.h>
 #  include <sys/sysctl.h>
 #elif DETECT_OS_APPLE || DETECT_OS_BSD
@@ -213,9 +213,13 @@ os_get_available_system_memory(uint64_t *size)
 
    free(meminfo);
    return false;
-#elif DETECT_OS_OPENBSD
+#elif defined(DETECT_OS_OPENBSD) || defined(DETECT_OS_FREEBSD)
    struct rlimit rl;
+#if DETECT_OS_OPENBSD
    int mib[] = { CTL_HW, HW_USERMEM64 };
+#elif DETECT_OS_FREEBSD
+   int mib[] = { CTL_HW, HW_USERMEM };
+#endif
    int64_t mem_available;
    size_t len = sizeof(mem_available);
 
