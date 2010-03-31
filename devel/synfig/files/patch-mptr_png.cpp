--- src/modules/mod_png/mptr_png.cpp.orig	2009-10-12 11:33:44.000000000 +0200
+++ src/modules/mod_png/mptr_png.cpp	2010-03-29 19:33:11.000000000 +0200
@@ -309,7 +309,7 @@
 				float b=gamma().b_U8_to_F32((unsigned char)png_ptr->palette[row_pointers[y][x]].blue);
 				float a=1.0;
 				if(info_ptr->valid & PNG_INFO_tRNS)
-				    a = (float)(unsigned char)png_ptr->trans[row_pointers[y][x]]*(1.0/255.0);
+				    a = (float)(unsigned char)png_ptr->trans_alpha[row_pointers[y][x]]*(1.0/255.0);
 				surface_buffer[y][x]=Color(
 					r,
 					g,
