--- lib/runtime/codec_c.c.orig	2026-10-31 12:09:53 UTC
+++ lib/runtime/codec_c.c
@@ -37,7 +37,7 @@ extern unsigned ZSTD_isError(size_t result);
 
 #include "vendor-xz-embedded/xz_config.h"
 #include "vendor-xz-embedded/xz.h"
-#include "bzlib.h"
+#include <bzlib.h>
 
 #define AWKTUA_CODEC_MAX_OUTPUT ((size_t)1 << 30)
 
