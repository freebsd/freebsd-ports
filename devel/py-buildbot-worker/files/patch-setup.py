--- setup.py.orig	2025-06-30 14:40:44 UTC
+++ setup.py
@@ -25,23 +25,30 @@ from setuptools.command.sdist import sdist
 from setuptools import Command
 from setuptools import setup
 from setuptools.command.sdist import sdist
+try:
+    from setuptools.command.install_data import install_data
+except ImportError:
+    from distutils.command.install_data import install_data
 
 from buildbot_worker import version
 
 BUILDING_WHEEL = bool("bdist_wheel" in sys.argv)
 
 
-class our_install_data(Command):
+class our_install_data(install_data):
     def initialize_options(self):
+        super().initialize_options()
         self.install_dir = None
 
     def finalize_options(self):
+        super().finalize_options()
         self.set_undefined_options(
             'install',
             ('install_lib', 'install_dir'),
         )
 
     def run(self):
+        super().run()
         # ensure there's a buildbot_worker/VERSION file
         fn = os.path.join(self.install_dir, 'buildbot_worker', 'VERSION')
         with open(fn, 'w') as f:
@@ -121,8 +128,6 @@ setup_args = {
     'entry_points': {
         'console_scripts': [
             'buildbot-worker=buildbot_worker.scripts.runner:run',
-            # this will also be shipped on non windows :-(
-            'buildbot_worker_windows_service=buildbot_worker.scripts.windows_service:HandleCommandLine',
         ]
     },
 }
@@ -143,10 +148,6 @@ setup_args['install_requires'] += [
     'autobahn >= 0.16.0',
     'msgpack >= 0.6.0',
 ]
-
-# buildbot_worker_windows_service needs pywin32
-if sys.platform == "win32":
-    setup_args['install_requires'].append('pywin32')
 
 # Unit test hard dependencies.
 test_deps = [
