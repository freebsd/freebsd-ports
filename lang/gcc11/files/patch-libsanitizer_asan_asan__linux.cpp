Since the vDSO shared librares on Linux and FreeBSD are called
differently, the initialization order check fails on FreeBSD.
This patch fixes it by ignoring [vdso] instead of linux-vdso.so.

GCC gets the original file from the LLVM Project, so this patch should
probably be upstreamed directly to the LLVM Project rather than to GCC.

--- libsanitizer/asan/asan_linux.cpp.orig	2022-11-23 10:52:45 UTC
+++ libsanitizer/asan/asan_linux.cpp
@@ -135,7 +135,7 @@ static int FindFirstDSOCallback(struct dl_phdr_info *i
     return 0;
 
   // Ignore vDSO
-  if (internal_strncmp(info->dlpi_name, "linux-", sizeof("linux-") - 1) == 0)
+  if (internal_strncmp(info->dlpi_name, "[vdso]", sizeof("[vdso]") - 1) == 0)
     return 0;
 
 #if SANITIZER_FREEBSD || SANITIZER_NETBSD
