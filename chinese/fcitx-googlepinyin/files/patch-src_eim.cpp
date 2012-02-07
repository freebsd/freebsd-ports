--- src/eim.cpp~	2012-01-31 09:03:36.000000000 -0600
+++ src/eim.cpp	2012-02-06 02:13:29.145600582 -0600
@@ -466,7 +466,7 @@ void* FcitxGooglePinyinCreate (FcitxInst
     if (fp)
         fclose(fp);
 
-    bool result = ime_pinyin::im_open_decoder(LIBDIR "/googlepinyin/data/dict_pinyin.dat", userDict);
+    bool result = ime_pinyin::im_open_decoder(DATADIR "/googlepinyin/dict_pinyin.dat", userDict);
 
     if (userDict)
         free(userDict);
