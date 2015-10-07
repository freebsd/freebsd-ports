--- setup.py.orig	2013-06-04 19:10:04 UTC
+++ setup.py
@@ -1,4 +1,24 @@
 from setuptools import setup
+from setuptools.command.test import test as TestCommand
+
+class PyTest(TestCommand):
+    user_options = [('pytest-args=', 'a', "Arguments to pass to py.test")]
+
+    def initialize_options(self):
+        TestCommand.initialize_options(self)
+        self.pytest_args = []
+
+    def finalize_options(self):
+        TestCommand.finalize_options(self)
+        self.test_args = []
+        self.test_suite = True
+
+    def run_tests(self):
+        # import here, because outside the eggs aren't loaded
+        import pytest
+        errno = pytest.main(self.pytest_args)
+        sys.exit(errno)
+
 setup(
     name='pytest-cache',
     description='pytest plugin with mechanisms for caching across test runs',
@@ -10,6 +30,8 @@ setup(
     py_modules=['pytest_cache'],
     entry_points={'pytest11': ['cacheprovider = pytest_cache']},
     install_requires=['pytest>=2.2', 'execnet>=1.1.dev1', ],
+    tests_require=['pytest'],
+    cmdclass={'test': PyTest},
     classifiers=[
             'Development Status :: 3 - Alpha',
             'Intended Audience :: Developers',
