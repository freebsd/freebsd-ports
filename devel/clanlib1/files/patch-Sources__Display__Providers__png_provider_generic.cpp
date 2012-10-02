--- ./Sources/Display/Providers/png_provider_generic.cpp.orig	2012-09-26 07:31:33.000000000 -0400
+++ ./Sources/Display/Providers/png_provider_generic.cpp	2012-09-26 07:32:16.000000000 -0400
@@ -107,7 +107,7 @@
 		png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
 		cl_assert(false);
 	}   
-	if (setjmp(png_ptr->jmpbuf))
+	if (setjmp(png_jmpbuf(png_ptr)))
 	{
 		png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
 		cl_assert(false);
