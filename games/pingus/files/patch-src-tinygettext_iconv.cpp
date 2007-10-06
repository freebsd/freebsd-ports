--- src/tinygettext/iconv.cpp	2007-10-05 11:17:23.000000000 -0500
+++ src/tinygettext/iconv.cpp	2007-10-05 11:17:35.000000000 -0500
@@ -78,7 +78,7 @@
   size_t in_size = text.size();
   size_t out_size = 4*in_size; // Worst case scenario: ASCII -> UTF-32?
   std::string result(out_size, ' ');
-  ICONV_CONST char* in_str  = &text[0];
+  const char* in_str  = &text[0];
   char* out_str = &result[0];
  
   // Try to convert the text.
