--- src/byteptr.h.orig	2021-10-10 01:56:02 UTC
+++ src/byteptr.h
@@ -83,6 +83,7 @@
 //
 // Write a value to a little-endian, unaligned destination.
 //
+#include "doomtype.h"
 FUNCINLINE static ATTRINLINE void writeshort(void *ptr, INT32 val)
 {
 	SINT8 *cp = ptr;
