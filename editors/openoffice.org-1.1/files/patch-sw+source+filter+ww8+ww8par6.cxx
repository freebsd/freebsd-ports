--- ../sw/source/filter/ww8/ww8par6.cxx.orig	2003-02-07 01:36:16.000000000 +0900
+++ ../sw/source/filter/ww8/ww8par6.cxx	2003-04-06 08:56:40.000000000 +0900
@@ -3352,9 +3352,11 @@
                 nId = RES_CHRATR_CTL_FONT;
                 break;
             case 93:
+            case 111:
             case 0x4a4f:
                 nId = RES_CHRATR_FONT;
                 break;
+            case 112:
             case 0x4a50:
                 nId = RES_CHRATR_CJK_FONT;
                 break;
@@ -4830,8 +4832,8 @@
                                                  //percentage to grow hps short
     {110, (FNReadRecord)0},                      //"sprmCCondHyhen", chp.ysri 
                                                  //ysri short
-    {111, (FNReadRecord)0},                      //"??111",
-    {112, (FNReadRecord)0},                      //"??112",
+    {111, &SwWW8ImplReader::Read_FontCode},      //ww7 font
+    {112, &SwWW8ImplReader::Read_FontCode},      //ww7 CJK font
     {113, &SwWW8ImplReader::Read_FontCode},      //ww7 rtl font
     {114, (FNReadRecord)0},                      //"??114",
     {115, &SwWW8ImplReader::Read_TxtColor},      //ww7 rtl colour ?
