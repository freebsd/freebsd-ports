--- programs/gaia/Texture.cc.orig	2006-11-29 04:21:14.000000000 +0100
+++ programs/gaia/Texture.cc	2010-03-29 14:33:38.000000000 +0200
@@ -277,7 +277,7 @@
 
 		fread(sig, 8, 1, infile);
 
-		if (!png_check_sig(sig, 8))
+		if (png_sig_cmp(sig, 0, 8))
 			throw Exception("bad PNG signature");
 
 		/* create structures */
@@ -308,7 +308,7 @@
 		switch (color_type) {
 		case PNG_COLOR_TYPE_GRAY:
 			if (bit_depth < 8)
-				png_set_gray_1_2_4_to_8(png_ptr);
+				png_set_expand_gray_1_2_4_to_8(png_ptr);
 			m_glInternalFormat = GL_LUMINANCE8;
 			m_glFormat = GL_LUMINANCE;
 			break;
