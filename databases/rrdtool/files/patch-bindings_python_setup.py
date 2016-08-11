--- bindings/python/setup.py.orig	2015-11-10 15:07:11 UTC
+++ bindings/python/setup.py
@@ -28,12 +28,7 @@
 #  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 #
 
-try:
-    # Attempt to build using Distribute, which also supports bdist_wheel
-    from setuptools import setup
-    from setuptools.extension import Extension
-except ImportError:
-    from distutils.core import setup, Extension
+from distutils.core import setup, Extension
 import sys, os
 
 TOP_SRCDIR = os.environ.get('ABS_TOP_SRCDIR', '../..')
