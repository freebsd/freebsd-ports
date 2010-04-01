--- src/other/tkimg/pngtcl/pngtclDecls.h.orig	2008-08-18 21:12:56.000000000 +0200
+++ src/other/tkimg/pngtcl/pngtclDecls.h	2010-04-01 07:15:04.000000000 +0200
@@ -46,11 +46,11 @@
 				png_voidp error_ptr, png_error_ptr error_fn,
 				png_error_ptr warn_fn));
 /* 6 */
-EXTERN png_uint_32	png_get_compression_buffer_size _ANSI_ARGS_((
+EXTERN png_size_t	png_get_compression_buffer_size _ANSI_ARGS_((
 				png_structp png_ptr));
 /* 7 */
 EXTERN void		png_set_compression_buffer_size _ANSI_ARGS_((
-				png_structp png_ptr, png_uint_32 size));
+				png_structp png_ptr, png_size_t size));
 /* 8 */
 EXTERN int		png_reset_zstream _ANSI_ARGS_((png_structp png_ptr));
 /* 9 */
@@ -337,7 +337,7 @@
 				png_bytep new_row));
 /* 94 */
 EXTERN png_voidp	png_malloc _ANSI_ARGS_((png_structp png_ptr,
-				png_uint_32 size));
+				png_size_t size));
 /* 95 */
 EXTERN void		png_free _ANSI_ARGS_((png_structp png_ptr,
 				png_voidp ptr));
@@ -351,7 +351,7 @@
 				png_uint_32 mask));
 /* 98 */
 EXTERN png_voidp	png_malloc_default _ANSI_ARGS_((png_structp png_ptr,
-				png_uint_32 size));
+				png_size_t size));
 /* 99 */
 EXTERN void		png_free_default _ANSI_ARGS_((png_structp png_ptr,
 				png_voidp ptr));
@@ -380,7 +380,7 @@
 EXTERN png_uint_32	png_get_valid _ANSI_ARGS_((png_structp png_ptr,
 				png_infop info_ptr, png_uint_32 flag));
 /* 108 */
-EXTERN png_uint_32	png_get_rowbytes _ANSI_ARGS_((png_structp png_ptr,
+EXTERN png_size_t	png_get_rowbytes _ANSI_ARGS_((png_structp png_ptr,
 				png_infop info_ptr));
 /* 109 */
 EXTERN png_bytepp	png_get_rows _ANSI_ARGS_((png_structp png_ptr,
