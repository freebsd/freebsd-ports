--- src/reader_util.cpp.orig	2015-09-14 08:49:23 UTC
+++ src/reader_util.cpp
@@ -310,11 +310,7 @@ std::string ReaderUtil::Recode(const std
 	size_t dst_size = str_to_encode.size() * 5 + 10;
 	char *dst = new char[dst_size];
 	size_t dst_left = dst_size;
-#    ifdef ICONV_CONST
-	char ICONV_CONST *p = src;
-#    else
-	char *p = src;
-#    endif
+	char const *p = src;
 	char *q = dst;
 	size_t status = iconv(cd, &p, &src_left, &q, &dst_left);
 	iconv_close(cd);
