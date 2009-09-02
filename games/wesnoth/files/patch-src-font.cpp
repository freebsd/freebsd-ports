Index: src/font.cpp
===================================================================
--- src/font.cpp	(revision 36766)
+++ src/font.cpp	(revision 37394)
@@ -50,10 +50,7 @@
 #define ERR_FT LOG_STREAM(err, log_font)
 
 #ifdef	HAVE_FRIBIDI
-#include <fribidi/fribidi.h>
-
-#else
-
+#include <fribidi.h>
 #endif
 
 namespace {
@@ -467,16 +464,25 @@
 void text_surface::bidi_cvt()
 {
 	char		*c_str = const_cast<char *>(str_.c_str());	// fribidi forgot const...
-	int		len = str_.length();
+	FriBidiStrIndex	len = str_.length();
 	FriBidiChar	*bidi_logical = new FriBidiChar[len + 2];
 	FriBidiChar	*bidi_visual = new FriBidiChar[len + 2];
 	char		*utf8str = new char[4*len + 1];	//assume worst case here (all 4 Byte characters)
 	FriBidiCharType	base_dir = FRIBIDI_TYPE_ON;
-	int n;
+	FriBidiStrIndex n;
 
+
+#ifdef	OLD_FRIBIDI
 	n = fribidi_utf8_to_unicode (c_str, len, bidi_logical);
+#else
+	n = fribidi_charset_to_unicode(FRIBIDI_CHAR_SET_UTF8, c_str, len, bidi_logical);
+#endif
 	fribidi_log2vis(bidi_logical, n, &base_dir, bidi_visual, NULL, NULL, NULL);
+#ifdef	OLD_FRIBIDI
 	fribidi_unicode_to_utf8 (bidi_visual, n, utf8str);
+#else
+	fribidi_unicode_to_charset(FRIBIDI_CHAR_SET_UTF8, bidi_visual, n, utf8str);
+#endif
 	is_rtl_ = base_dir == FRIBIDI_TYPE_RTL;
 	str_ = std::string(utf8str);
 	delete[] bidi_logical;
