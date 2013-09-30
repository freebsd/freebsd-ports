--- test/examples_test.py.orig	2013-09-30 22:50:22.000000000 +0200
+++ test/examples_test.py	2013-09-30 22:50:39.000000000 +0200
@@ -18,7 +18,7 @@
   examples/cairo_snippets/snippets/
   '''
   def doSnippets(name):
-    retcode = subprocess.call('python %s -s' % name, shell=True)
+    retcode = subprocess.call('python2 %s -s' % name, shell=True)
     assert retcode == 0, 'Error: retcode == {0}'.format(retcode)
 
   os.chdir(os.path.join(os.path.dirname(__file__), '..', 'examples',
