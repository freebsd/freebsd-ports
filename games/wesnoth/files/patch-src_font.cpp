--- src/font.cpp.orig	2009-08-24 23:47:26.000000000 -0400
+++ src/font.cpp	2009-08-24 23:48:51.000000000 -0400
@@ -474,9 +474,9 @@ void text_surface::bidi_cvt()
 	FriBidiCharType	base_dir = FRIBIDI_TYPE_ON;
 	int n;
 
-	n = fribidi_utf8_to_unicode (c_str, len, bidi_logical);
+	n = fribidi_charset_to_unicode (FRIBIDI_CHAR_SET_UTF8, c_str, len, bidi_logical);
 	fribidi_log2vis(bidi_logical, n, &base_dir, bidi_visual, NULL, NULL, NULL);
-	fribidi_unicode_to_utf8 (bidi_visual, n, utf8str);
+	fribidi_unicode_to_charset (FRIBIDI_CHAR_SET_UTF8, bidi_visual, n, utf8str);
 	is_rtl_ = base_dir == FRIBIDI_TYPE_RTL;
 	str_ = std::string(utf8str);
 	delete[] bidi_logical;
