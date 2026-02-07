--- src/DoublePinyinContext.cc.orig	2019-09-09 19:45:16 UTC
+++ src/DoublePinyinContext.cc
@@ -352,7 +352,7 @@ DoublePinyinContext::isPinyin (int i)
         return NULL;
     }
 
-    char sheng = ID_TO_SHENG (i);
+    signed char sheng = ID_TO_SHENG (i);
 
     if (sheng == PINYIN_ID_VOID) {
         return NULL;
@@ -365,8 +365,8 @@ inline const Pinyin *
 DoublePinyinContext::isPinyin (int i, int j)
 {
     const Pinyin *pinyin = NULL;
-    char sheng = ID_TO_SHENG (i);
-    const char *yun = ID_TO_YUNS (j);
+    signed char sheng = ID_TO_SHENG (i);
+    const signed char *yun = ID_TO_YUNS (j);
 
     do {
         if (sheng == PINYIN_ID_VOID || yun[0] == PINYIN_ID_VOID)
