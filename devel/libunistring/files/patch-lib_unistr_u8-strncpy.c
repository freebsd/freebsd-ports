--- lib/unistr/u8-strncpy.c.orig	2024-01-29 00:58:11 UTC
+++ lib/unistr/u8-strncpy.c
@@ -28,10 +28,6 @@
 /* Specification.  */
 #include "unistr.h"
 
-#include <string.h>
-
-uint8_t *
-u8_strncpy (uint8_t *dest, const uint8_t *src, size_t n)
-{
-  return (uint8_t *) strncpy ((char *) dest, (const char *) src, n);
-}
+#define FUNC u8_strncpy
+#define UNIT uint8_t
+#include "u-strncpy.h"
