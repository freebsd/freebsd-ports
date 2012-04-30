--- src/eim.cpp.orig	2012-03-08 22:07:27.000000000 -0600
+++ src/eim.cpp	2012-04-06 02:04:15.502210235 -0500
@@ -476,7 +476,7 @@ void* FcitxGooglePinyinCreate (FcitxInst
     else 
 #endif
     {
-        syspath = strdup(GOOGLEPINYIN_LIBDIR "/googlepinyin/data/dict_pinyin.dat");
+        syspath = strdup(GOOGLEPINYIN_LIBDIR "/../share/googlepinyin/dict_pinyin.dat");
     }
     bool result = ime_pinyin::im_open_decoder(syspath, userDict);
     free(syspath);
