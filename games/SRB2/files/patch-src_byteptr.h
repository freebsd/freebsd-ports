--- src/byteptr.h.orig	2025-01-25 22:35:40 UTC
+++ src/byteptr.h
@@ -56,6 +56,7 @@
 //
 // Write a value to a little-endian, unaligned destination.
 //
+#include "doomtype.h"
 FUNCINLINE static ATTRINLINE void writeshort(void *ptr, INT32 val)
 {
 	SINT8 *cp = ptr;
