--- setup.py.orig	2025-06-30 15:33:51 UTC
+++ setup.py
@@ -28,25 +28,32 @@ from setuptools.command.sdist import sdist
 
 from setuptools import Command
 from setuptools.command.sdist import sdist
+try:
+    from setuptools.command.install_data import install_data
+except ImportError:
+    from distutils.command.install_data import install_data
 
 from buildbot import version
 
 BUILDING_WHEEL = bool("bdist_wheel" in sys.argv)
 
 
-class install_data_twisted(Command):
+class install_data_twisted(install_data):
     """make sure VERSION file is installed in package."""
 
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
         # ensure there's a buildbot/VERSION file
         fn = os.path.join(self.install_dir, 'buildbot', 'VERSION')
         with open(fn, 'w') as f:
@@ -640,8 +647,6 @@ setup_args = {
         {
             'console_scripts': [
                 'buildbot=buildbot.scripts.runner:run',
-                # this will also be shipped on non windows :-(
-                'buildbot_windows_service=buildbot.scripts.windows_service:HandleCommandLine',
             ]
         },
     ),
