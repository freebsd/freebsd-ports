# modernize buildbot_worker setup.py with package_data
# https://github.com/buildbot/buildbot/pull/4394

--- setup.py.orig	2018-10-09 18:37:18 UTC
+++ setup.py
@@ -31,23 +31,6 @@ from distutils.core import setup
 from buildbot_worker import version
 
 
-class our_install_data(install_data):
-
-    def finalize_options(self):
-        self.set_undefined_options('install',
-                                   ('install_lib', 'install_dir'),
-                                   )
-        install_data.finalize_options(self)
-
-    def run(self):
-        install_data.run(self)
-        # ensure there's a buildbot_worker/VERSION file
-        fn = os.path.join(self.install_dir, 'buildbot_worker', 'VERSION')
-        with open(fn, 'w') as f:
-            f.write(version)
-        self.outfiles.append(fn)
-
-
 class our_sdist(sdist):
 
     def make_release_tree(self, base_dir, files):
@@ -105,11 +88,12 @@ setup_args = {
         "buildbot_worker.test.unit",
         "buildbot_worker.test.util",
     ],
-    # mention data_files, even if empty, so install_data is called and
-    # VERSION gets copied
-    'data_files': [("buildbot_worker", [])],
+    'package_data': {
+        '': [
+            'VERSION',
+        ]
+    },
     'cmdclass': {
-        'install_data': our_install_data,
         'sdist': our_sdist
     },
     'entry_points': {
