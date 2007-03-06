--- trac/mimeview/api.py.orig	Tue Mar  6 16:30:30 2007
+++ trac/mimeview/api.py	Tue Mar  6 16:30:40 2007
@@ -319,7 +319,7 @@
     annotators = ExtensionPoint(IHTMLPreviewAnnotator)
     converters = ExtensionPoint(IContentConverter)
 
-    default_charset = Option('trac', 'default_charset', 'iso-8859-15',
+    default_charset = Option('trac', 'default_charset', 'utf-8',
         u"""文字コードが設定されていないときのデフォルト値を設定します。""")
 
     tab_width = IntOption('mimeviewer', 'tab_width', 8,
