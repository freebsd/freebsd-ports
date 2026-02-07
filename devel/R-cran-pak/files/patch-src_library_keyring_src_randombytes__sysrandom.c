--- src/library/keyring/src/randombytes_sysrandom.c.orig	2025-06-10 06:25:27 UTC
+++ src/library/keyring/src/randombytes_sysrandom.c
@@ -32,6 +32,7 @@
 # endif
 #elif defined(__FreeBSD__) || defined(__DragonFly__)
 # include <sys/param.h>
+# include <sys/random.h>
 # if (defined(__FreeBSD_version) && __FreeBSD_version >= 1200000) || \
      (defined(__DragonFly_version) && __DragonFly_version >= 500700)
 #  define HAVE_LINUX_COMPATIBLE_GETRANDOM
