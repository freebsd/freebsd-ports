--- Lib/email/Charset.py.orig	Sat Dec 20 15:16:29 2003
+++ Lib/email/Charset.py	Sat Dec 20 15:16:54 2003
@@ -99,13 +99,13 @@
 # of stability and useability.
 
 CODEC_MAP = {
-    'euc-jp':      'japanese.euc-jp',
-    'iso-2022-jp': 'japanese.iso-2022-jp',
-    'shift_jis':   'japanese.shift_jis',
-    'euc-kr':      'korean.euc-kr',
-    'ks_c_5601-1987': 'korean.cp949',
-    'iso-2022-kr': 'korean.iso-2022-kr',
-    'johab':       'korean.johab',
+    'euc-jp':      'euc-jp',
+    'iso-2022-jp': 'iso-2022-jp',
+    'shift_jis':   'shift_jis',
+    'euc-kr':      'euc-kr',
+    'ks_c_5601-1987': 'cp949',
+    'iso-2022-kr': 'iso-2022-kr',
+    'johab':       'johab',
     'gb2132':      'eucgb2312_cn',
     'big5':        'big5_tw',
     'utf-8':       'utf-8',
