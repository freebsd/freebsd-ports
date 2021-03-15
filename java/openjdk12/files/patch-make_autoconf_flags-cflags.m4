--- make/autoconf/flags-cflags.m4.orig	2020-01-08 09:12:31 UTC
+++ make/autoconf/flags-cflags.m4
@@ -770,6 +770,14 @@ AC_DEFUN([FLAGS_SETUP_CFLAGS_CPU_DEP],
         # for all archs except arm and ppc, prevent gcc to omit frame pointer
         $1_CFLAGS_CPU_JDK="${$1_CFLAGS_CPU_JDK} -fno-omit-frame-pointer"
       fi
+    elif test "x$OPENJDK_TARGET_OS_ENV" = xbsd.freebsd; then
+        if test "x$FLAGS_CPU" = xppc64; then
+            $1_CFLAGS_CPU_JVM="${$1_CFLAGS_CPU_JVM} -DABI_ELFv2 -mcpu=powerpc64 -mtune=power5"
+	 elif test "x$FLAGS_CPU" = xppc64le; then
+	     # Little endian machine uses ELFv2 ABI.
+	     # Use Power8, this is the first CPU to support PPC64 LE with ELFv2 ABI.
+	     $1_CFLAGS_CPU_JVM="${$1_CFLAGS_CPU_JVM} -DABI_ELFv2 -mcpu=power8 -mtune=power8"
+        fi
     fi
 
   elif test "x$TOOLCHAIN_TYPE" = xsolstudio; then
