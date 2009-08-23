--- src/effect/Font.cpp.orig	2009-08-23 13:13:38.000000000 -0400
+++ src/effect/Font.cpp	2009-08-23 13:14:57.000000000 -0400
@@ -26,7 +26,7 @@ Font::biditize(const std::string &text)
     FriBidiChar *logicalString = new FriBidiChar[text.length() + 1];
     FriBidiChar *visualString = new FriBidiChar[text.length() + 1];
 
-    int ucsLength = fribidi_utf8_to_unicode(const_cast<char*>(text.c_str()),
+    int ucsLength = fribidi_charset_to_unicode(FRIBIDI_CHAR_SET_UTF8, const_cast<char*>(text.c_str()),
             text.length(), logicalString);
     fribidi_boolean ok = fribidi_log2vis(logicalString, ucsLength, &base,
             visualString, NULL, NULL, NULL);
@@ -37,7 +37,7 @@ Font::biditize(const std::string &text)
     }
 
     char *buffer = new char[text.length() + 1];
-    int length = fribidi_unicode_to_utf8(visualString, ucsLength, buffer);
+    int length = fribidi_unicode_to_charset(FRIBIDI_CHAR_SET_UTF8, visualString, ucsLength, buffer);
     std::string result = std::string(buffer, length);
     delete[] buffer;
     delete[] visualString;
