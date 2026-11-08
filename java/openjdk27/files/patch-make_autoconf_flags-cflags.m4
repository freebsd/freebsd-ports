--- make/autoconf/flags-cflags.m4.orig	2025-09-16 10:24:48 UTC
+++ make/autoconf/flags-cflags.m4
@@ -780,6 +780,9 @@ AC_DEFUN([FLAGS_SETUP_CFLAGS_CPU_DEP],
         # Use Power8, this is the first CPU to support PPC64 LE with ELFv2 ABI.
         $1_CFLAGS_CPU_JVM="${$1_CFLAGS_CPU_JVM} -DABI_ELFv2 -mcpu=power8 -mtune=power10"
       fi
+      if test "x$FLAGS_CPU" = xppc64; then
+        $1_CFLAGS_CPU_JVM="${$1_CFLAGS_CPU_JVM} -DABI_ELFv2 -mcpu=powerpc64 -mtune=power5"
+      fi
     fi
     if test "x$OPENJDK_TARGET_OS" = xaix; then
       $1_CFLAGS_CPU="-mcpu=pwr8"
