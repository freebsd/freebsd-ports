--- src/kex/i_png.h.orig	2026-10-15 11:58:04 UTC
+++ src/kex/i_png.h
@@ -23,7 +23,7 @@
 #ifndef __I_PNG_H__
 #define __I_PNG_H__
 
-#include <libpng15/png.h>
+#include <png.h>
 #include "doomtype.h"
 
 byte* I_PNGReadData(int lump, dboolean palette, dboolean nopack, dboolean alpha,
