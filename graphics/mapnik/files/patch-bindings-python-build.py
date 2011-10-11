--- bindings/python/build.py.orig	2011-10-08 18:47:26.408387316 +0400
+++ bindings/python/build.py	2011-10-08 18:49:32.905390831 +0400
@@ -144,10 +144,6 @@
     os.mkdir('mapnik')
 file('mapnik/paths.py','w').write(paths % (env['MAPNIK_LIB_DIR']))
 
-try:
-    os.chmod('mapnik/paths.py',0666)
-except: pass
-
 # install the core mapnik python files, including '__init__.py' and 'paths.py'
 if 'install' in COMMAND_LINE_TARGETS:
     init_files = glob.glob('mapnik/*.py')