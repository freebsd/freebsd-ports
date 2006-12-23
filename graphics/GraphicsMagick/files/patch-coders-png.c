--- coders/png.c	2004/11/11 03:10:42	1.369.2.3
+++ coders/png.c	2006/08/18 04:03:02	1.369.2.4
@@ -1709,7 +1709,7 @@ static Image *ReadOnePNGImage(MngInfo *m
 #if defined(PNG_USE_PNGGCCRD) && defined(PNG_ASSEMBLER_CODE_SUPPORTED) \
 && (PNG_LIBPNG_VER >= 10200)
   /* Disable thread-unsafe features of pnggccrd */
-  if (png_access_version() >= 10200)
+  if (png_access_version_number() >= 10200)
   {
     png_uint_32 mmx_disable_mask=0;
     png_uint_32 asm_flags;
@@ -1718,8 +1718,8 @@ static Image *ReadOnePNGImage(MngInfo *m
                         | PNG_ASM_FLAG_MMX_READ_FILTER_SUB   \
                         | PNG_ASM_FLAG_MMX_READ_FILTER_AVG   \
                         | PNG_ASM_FLAG_MMX_READ_FILTER_PAETH );
-    asm_flags=png_get_asm_flags(png_ptr);
-    png_set_asm_flags(png_ptr, asm_flags & ~mmx_disable_mask);
+    asm_flags=png_get_asm_flags(ping);
+    png_set_asm_flags(ping, asm_flags & ~mmx_disable_mask);
   }
 #endif
 
