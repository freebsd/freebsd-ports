# Fix tests running twice
# TODO: Upstream

# Register six dependency
# https://github.com/google/pasta/pull/77

--- setup.py.orig	2019-05-29 17:07:01 UTC
+++ setup.py
@@ -26,7 +26,8 @@ def all_tests():
     test_suite = test_loader.discover('.', pattern='*_test.py')
     return test_suite
 
-setup(
+if __name__ == '__main__':
+  setup(
     name="google-pasta",
     version="0.1.7",
     packages=find_packages(),
@@ -43,4 +44,7 @@ setup(
         "Development Status :: 2 - Pre-Alpha",
         "License :: OSI Approved :: Apache Software License",
     ],
-)
+    install_requires=[
+        'six',
+    ],
+  )
