--- setup.py	2007-11-17 18:13:24.000000000 +0100
+++ setup.py.port	2008-02-16 14:36:17.000000000 +0100
@@ -51,6 +51,13 @@
             print '  problem: %s' % e
             print '=' * 79
 
+if not os.environ.has_key('NOPORTDOCS'):
+    port_data_files=[
+        ('docs/html', list(list_files('docs/html'))),
+        ('docs/txt', list(list_files('docs/src')))
+    ]
+else:
+    port_data_files=[]
 
 setup(
     name='Jinja',
@@ -78,10 +85,7 @@
     ],
     keywords=['python.templating.engines'],
     packages=['jinja', 'jinja.translators'],
-    data_files=[
-        ('docs/html', list(list_files('docs/html'))),
-        ('docs/txt', list(list_files('docs/src')))
-    ],
+    data_files=port_data_files,
     entry_points='''
     [python.templating.engines]
     jinja = jinja.plugin:BuffetPlugin
