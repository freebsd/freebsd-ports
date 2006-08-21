--- coders/png.c.orig	Thu Nov 11 07:14:54 2004
+++ coders/png.c	Sun Aug 20 15:21:14 2006
@@ -71,7 +71,7 @@
 #include "magick/transform.h"
 #include "magick/utility.h"
 #if defined(HasPNG)
-#include "png.h"
+#include "libpng/png.h"
 #include "zlib.h"
 
 #if PNG_LIBPNG_VER > 95
@@ -1567,6 +1567,8 @@
     num_passes,
     pass;
 
+  png_structp png_ptr;
+
   PixelPacket
     transparent_color;
 
@@ -1709,18 +1711,6 @@
 #if defined(PNG_USE_PNGGCCRD) && defined(PNG_ASSEMBLER_CODE_SUPPORTED) \
 && (PNG_LIBPNG_VER >= 10200)
   /* Disable thread-unsafe features of pnggccrd */
-  if (png_access_version() >= 10200)
-  {
-    png_uint_32 mmx_disable_mask=0;
-    png_uint_32 asm_flags;
-
-    mmx_disable_mask |= ( PNG_ASM_FLAG_MMX_READ_COMBINE_ROW  \
-                        | PNG_ASM_FLAG_MMX_READ_FILTER_SUB   \
-                        | PNG_ASM_FLAG_MMX_READ_FILTER_AVG   \
-                        | PNG_ASM_FLAG_MMX_READ_FILTER_PAETH );
-    asm_flags=png_get_asm_flags(png_ptr);
-    png_set_asm_flags(png_ptr, asm_flags & ~mmx_disable_mask);
-  }
 #endif
 
   png_read_info(ping,ping_info);
