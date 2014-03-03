--- ./setup.py.orig	2007-11-17 20:13:24.000000000 +0300
+++ ./setup.py	2014-03-03 13:21:43.000000000 +0400
@@ -78,10 +78,7 @@
     ],
     keywords=['python.templating.engines'],
     packages=['jinja', 'jinja.translators'],
-    data_files=[
-        ('docs/html', list(list_files('docs/html'))),
-        ('docs/txt', list(list_files('docs/src')))
-    ],
+    data_files=[],
     entry_points='''
     [python.templating.engines]
     jinja = jinja.plugin:BuffetPlugin
