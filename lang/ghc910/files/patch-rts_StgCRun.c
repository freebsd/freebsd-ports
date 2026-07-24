--- rts/StgCRun.c.orig
+++ rts/StgCRun.c
@@ -670,7 +670,7 @@
    Everything is in assembler, so we don't have to deal with GCC...
    -------------------------------------------------------------------------- */

-#if defined(powerpc64_HOST_ARCH)
+#if defined(powerpc64_HOST_ARCH) && !defined(freebsd_HOST_OS)
 /* 64-bit PowerPC ELF ABI 1.9
  *
  * Stack frame organization (see Figure 3-17, ELF ABI 1.9, p 14)
