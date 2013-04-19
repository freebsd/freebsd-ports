--- Source/Core/Common/Src/StringUtil.cpp.orig	2013-03-21 06:49:23.000000000 +0100
+++ Source/Core/Common/Src/StringUtil.cpp	2013-03-21 06:50:08.000000000 +0100
@@ -460,7 +460,7 @@
 
 		while (src_bytes != 0)
 		{
-			size_t const iconv_result = iconv(conv_desc, (char**)(&src_buffer), &src_bytes,
+			size_t const iconv_result = iconv(conv_desc, (const char**)(&src_buffer), &src_bytes,
 				&dst_buffer, &dst_bytes);
 
 			if ((size_t)-1 == iconv_result)
