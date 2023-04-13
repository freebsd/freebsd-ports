--- parpar/src/cpuid.h.orig	2023-03-22 08:33:16 UTC
+++ parpar/src/cpuid.h
@@ -42,12 +42,13 @@
 # ifdef __ANDROID__
 // TODO: may be better to prefer auxv as it's supported
 #  include <cpu-features.h>
-# elif defined(__linux__) || (defined(__FreeBSD__) && __FreeBSD__ >= 12)
+# elif defined(__linux__)
 #  include <sys/auxv.h>
 #  include <asm/hwcap.h>
+# elif (defined(__FreeBSD__) && __FreeBSD__ >= 12)
+#  include <sys/auxv.h>
 # elif (defined(__FreeBSD__) && __FreeBSD__ < 12)
 #  include <sys/sysctl.h>
-#  include <asm/hwcap.h>
 # elif defined(_WIN32)
 #  define WIN32_LEAN_AND_MEAN
 #  define NOMINMAX
