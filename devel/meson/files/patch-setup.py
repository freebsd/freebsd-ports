From 999669e8501501d4618588008e4bf4353a1ace2a Mon Sep 17 00:00:00 2001
From: Patrick Griffis <tingping@tingping.se>
Date: Fri, 30 Sep 2016 23:28:40 -0400
Subject: [PATCH] setup.py: On Unix install scripts without .py suffix

--- setup.py.orig	2016-10-17 17:38:14 UTC
+++ setup.py
@@ -14,7 +14,9 @@
 # See the License for the specific language governing permissions and
 # limitations under the License.
 
+import os
 import sys
+from os import path
 
 if sys.version_info[0] < 3:
     print('Tried to install with Python 2, Meson only supports Python 3.')
@@ -25,8 +27,32 @@ if sys.version_info[0] < 3:
 # plain distutils when setuptools is not available.
 try:
     from setuptools import setup
+    from setuptools.command.install_scripts import install_scripts as orig
 except ImportError:
     from distutils.core import setup
+    from distutils.command.install_scripts import install_scripts as orig
+
+from distutils.file_util import copy_file
+from distutils.dir_util import mkpath
+from stat import ST_MODE
+
+class install_scripts(orig):
+    def run(self):
+        if sys.platform == 'win32':
+            super().run()
+            return
+
+        self.outfiles = []
+        if not self.dry_run:
+            mkpath(self.install_dir)
+
+        # We want the files to be installed without a suffix on Unix
+        for infile in self.get_inputs():
+            in_stripped = infile[:-3] if infile.endswith('.py') else infile
+            outfile = path.join(self.install_dir, in_stripped)
+            # NOTE: Mode is preserved by default
+            copy_file(infile, outfile, dry_run=self.dry_run)
+            self.outfiles.append(outfile)
 
 from mesonbuild.coredata import version
 
@@ -46,7 +72,8 @@ setup(name='meson',
                'mesonconf.py',
                'mesonintrospect.py',
                'wraptool.py'],
-      data_files=[('share/man/man1', ['man/meson.1',
+      cmdclass={'install_scripts': install_scripts},
+      data_files=[('man/man1'      , ['man/meson.1',
                                       'man/mesonconf.1',
                                       'man/mesonintrospect.1',
                                       'man/wraptool.1'])],
