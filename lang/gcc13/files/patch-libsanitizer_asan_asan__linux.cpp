Since the vDSO shared librares on Linux and FreeBSD are called
differently, the initialization order check fails on FreeBSD.
This patch fixes it by ignoring [vdso] instead of linux-vdso.so.

GCC gets the original file from the LLVM Project, so this patch should
probably be upstreamed directly to the LLVM Project rather than to GCC.


--- libsanitizer/asan/asan_linux.cpp.orig	2022-11-23 11:22:41 UTC
+++ libsanitizer/asan/asan_linux.cpp
@@ -148,6 +148,12 @@ static int FindFirstDSOCallback(struct dl_phdr_info *i
     return 0;
 #    endif
 
+#    if SANITIZER_FREEBSD
+  // Ignore vDSO
+  if (internal_strncmp(info->dlpi_name, "[vdso]", sizeof("[vdso]") - 1) == 0)
+    return 0;
+#    endif
+
   *name = info->dlpi_name;
   return 1;
 }
