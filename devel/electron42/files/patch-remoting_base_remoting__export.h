--- remoting/base/remoting_export.h.orig	2026-04-28 21:06:17 UTC
+++ remoting/base/remoting_export.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 // On Linux, we need to export this symbol so it can be used by binaries that
 // link against remoting_core.so.
 #if defined(WIN32)
