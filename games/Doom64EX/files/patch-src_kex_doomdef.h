--- src/kex/doomdef.h.orig	2026-02-14 18:11:41 UTC
+++ src/kex/doomdef.h
@@ -37,6 +37,7 @@
 #else
 #include <stdio.h>
 #undef dprintf
+#define dprintf d64_dprintf
 #endif
 
 #include "doomtype.h"
