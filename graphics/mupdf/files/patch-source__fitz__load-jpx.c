--- source/fitz/load-jpx.c.orig	2016-11-28 13:34:04 UTC
+++ source/fitz/load-jpx.c
@@ -481,15 +481,7 @@ fz_load_jpx_info(fz_context *ctx, unsign
 
 #else /* HAVE_LURATECH */
 
-/* Without the definition of OPJ_STATIC, compilation fails on windows
- * due to the use of __stdcall. We believe it is required on some
- * linux toolchains too. */
-#define OPJ_STATIC
-#ifndef _MSC_VER
-#define OPJ_HAVE_STDINT_H
-#endif
-
-#include <openjpeg.h>
+#include <openjpeg-2.1/openjpeg.h>
 
 /* OpenJPEG does not provide a safe mechanism to intercept
  * allocations. In the latest version all allocations go
