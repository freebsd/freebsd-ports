--- src/pngxtern/pngxmem.c.orig	2015-04-22 09:07:30 UTC
+++ src/pngxtern/pngxmem.c
@@ -34,7 +34,7 @@ pngx_malloc_rows_extended(png_structp pn
       png_error(png_ptr, "Missing IHDR");
    row_size = png_get_rowbytes(png_ptr, info_ptr);
    /* libpng sets row_size to 0 when the width is too large to process. */
-   if (row_size == 0 || height > (pngx_alloc_size_t)(-1) / sizeof(png_bytep))
+   if (row_size == 0 || height > (pngx_alloc_size_t)(-1U) / sizeof(png_bytep))
       png_error(png_ptr, "Can't handle exceedingly large image dimensions");
    if (row_size < min_row_size)
       row_size = min_row_size;
