--- setup.py.orig	2021-11-12 09:24:24 UTC
+++ setup.py
@@ -30,17 +30,8 @@ DEV_STATUS = {'pre': '2 - Pre-Alpha',
 CMD_PACKAGES = {
     'sdist': 'setuptools.command',
     'bdist': 'distutils.command',
-    'bdist_wheel': 'wheel',
     'bdist_egg': 'setuptools.command',
-    'bdist_rpm': 'setuptools.command',
 }
-
-try:
-    from setuptools.command import bdist_wininst
-    CMD_PACKAGES['bdist_wininst'] = 'setuptools.command'
-except ImportError:
-    # python > 3.10
-    pass
 
 
 class PredistBuild(object):
