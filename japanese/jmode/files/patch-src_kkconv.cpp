--- src/kkconv.cpp.orig	2002-06-15 14:05:09 UTC
+++ src/kkconv.cpp
@@ -18,10 +18,12 @@
 #  include <alloca.h>
 # endif
 #endif
+#include <stdlib.h>
+#include <string.h>
 
 // 平乓仿弁正戊□玉32井日﹜
 //仇及末□旦反EUC匹踏井木化中月﹝
-static char *ascii_wide_tab[]={
+static const char *ascii_wide_tab[]={
     0,"〞","﹎","↑","♀","⊙","↓","﹊",
     "﹋","﹌","←","≒","﹞","≡","‘","▼",
     "ㄟ","ㄠ","ㄡ","ㄢ","ㄣ","ㄤ","ㄥ","ㄦ",
@@ -325,9 +327,9 @@ KKContext *createKKContext(XimIC *ic)
     return c;
 }
 
-char **getKKIcon()
+const char **getKKIcon()
 {
-    char **c;
+    const char **c;
     c = NULL;
     if (current_conv) {
         c = current_conv->getIcon ();
@@ -338,7 +340,7 @@ char **getKKIcon()
 // tool bar及移抩期儂庍晶及示正件互瓷今木凶﹝
 void onPushIcon()
 {
-    char **c=0;
+    const char **c=0;
     if (current_conv) {
 	c = current_conv->getIcon ();
 	if (c) {
