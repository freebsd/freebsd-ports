--- src/tinygettext/tinygettext.cpp.orig	Sat Jul  2 19:58:07 2005
+++ src/tinygettext/tinygettext.cpp	Thu Jun 14 16:12:51 2007
@@ -50,7 +50,7 @@
   strcpy(in_orig, text.c_str());
 
   char* out = out_orig;
-  ICONV_CONST char* in  = in_orig;
+  const char* in  = in_orig;
   size_t out_len_temp = out_len; // iconv is counting down the bytes it has
                                  // written from this...
 
