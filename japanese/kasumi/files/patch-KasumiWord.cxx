--- KasumiWord.cxx.orig	Mon Jan 10 20:30:37 2005
+++ KasumiWord.cxx	Mon Jan 10 20:38:01 2005
@@ -16,24 +16,27 @@
 string KasumiWord::convertUTF8ToEUCJP(const string &aUTF8){
   char *utf8 = (char*)malloc(strlen(aUTF8.c_str())+1);
   strcpy(utf8, aUTF8.c_str());
+  const char *ptr_utf8 = utf8;
   size_t len = strlen(utf8)+1;
   size_t len_eucjp = len*2;
   char *eucjp_buf = (char*)malloc(len_eucjp);
   char *eucjp = eucjp_buf;
 
-  iconv(IconvUTF8_To_EUCJP, &utf8, &len, &eucjp_buf, &len_eucjp);
+  iconv(IconvUTF8_To_EUCJP, &ptr_utf8, &len, &eucjp_buf, &len_eucjp);
   return string(eucjp);
 }
 
 string KasumiWord::convertEUCJPToUTF8(const string &aEUCJP){
   char *eucjp = (char*)malloc(strlen(aEUCJP.c_str())+1);
   strcpy(eucjp, aEUCJP.c_str());
+  const char *ptr_eucjp = eucjp;
   size_t len = strlen(eucjp)+1;
   size_t len_utf8 = len*2;
   char *utf8_buf = (char*)malloc(len_utf8);
   char *utf8 = utf8_buf;
 
-  iconv(IconvEUCJP_To_UTF8, &eucjp, &len, &utf8_buf, &len_utf8);
+
+  iconv(IconvEUCJP_To_UTF8, &ptr_eucjp, &len, &utf8_buf, &len_utf8);
   return string(utf8);
 }
 
