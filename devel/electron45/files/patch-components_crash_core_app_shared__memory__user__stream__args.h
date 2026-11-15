--- components/crash/core/app/shared_memory_user_stream_args.h.orig	2026-10-19 21:50:55 UTC
+++ components/crash/core/app/shared_memory_user_stream_args.h
@@ -15,7 +15,7 @@ static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 #include "build/build_config.h"
 
 static_assert(BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) ||
-                  BUILDFLAG(IS_CHROMEOS),
+                  BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD),
               "Unsupported platform.");
 
 #include <set>
