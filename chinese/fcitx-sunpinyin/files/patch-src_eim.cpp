--- src/eim.cpp.orig	2011-09-29 01:58:59.000000000 -0500
+++ src/eim.cpp	2011-11-11 02:25:11.839864988 -0600
@@ -229,8 +229,6 @@ INPUT_RETURN_VALUE FcitxSunpinyinGetCand
            (ppd.size() - ppd.caret() + 1) * sizeof(TWCHAR));
     memcpy(sunpinyin->input_src, src, hzlen * sizeof(TWCHAR));
     
-    FcitxLog(INFO, "%d", ppd.candi_start());
-
     sunpinyin->front_src[ppd.caret()] = 0;
     sunpinyin->end_src[ppd.size() - ppd.caret() + 1] = 0;
     sunpinyin->input_src[hzlen] = 0;
