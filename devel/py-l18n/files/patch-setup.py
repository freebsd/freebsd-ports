--- setup.py.orig	2020-10-31 03:58:31 UTC
+++ setup.py
@@ -69,7 +69,7 @@ class PredistBuild(object):
         log.info('translation files built successfully')
 
 cmd_classes = {}
-for cmd in ('sdist', 'bdist', 'bdist_egg', 'bdist_rpm', 'bdist_wininst'):
+for cmd in ('sdist', 'bdist', 'bdist_egg'):
     try:
         cmd_module = getattr(__import__('setuptools.command', fromlist=[cmd]),
                              cmd)
