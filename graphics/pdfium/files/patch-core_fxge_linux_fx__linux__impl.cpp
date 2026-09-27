-- Allow the Linux font-info implementation to compile on FreeBSD; the code is
-- otherwise POSIX-compatible and uses the same font directories.
--- core/fxge/linux/fx_linux_impl.cpp.orig	2026-09-24 10:57:02 UTC
+++ core/fxge/linux/fx_linux_impl.cpp
@@ -18,7 +18,8 @@
 #include "core/fxge/fx_font.h"
 #include "core/fxge/systemfontinfo_iface.h"
 
-#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !defined(OS_ASMJS)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD) && \
+    !defined(OS_ASMJS)
 #error "Included on the wrong platform"
 #endif
 
