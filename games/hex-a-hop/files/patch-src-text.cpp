--- src/text.cpp~
+++ src/text.cpp
@@ -439,7 +439,7 @@ void ConvertToUTF8(const std::string &te
 	errno = 0;
 	static const char *locale_enc = gettext_init.GetEncoding();
 	iconv_t cd = iconv_open("UTF-8", locale_enc);
-	char *in_buf = const_cast<char *>(&text_locally_encoded[0]);
+	const char *in_buf = const_cast<char *>(&text_locally_encoded[0]);
 	char *out_buf = &text_utf8[0];
 	iconv(cd, &in_buf, &text_length, &out_buf, &text_utf8_length);
 	iconv_close(cd);
