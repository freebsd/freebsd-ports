-- Exclude benchmarks from installation to avoid top-level directory conflict

--- setup.py.orig	2026-06-12 02:50:19 UTC
+++ setup.py
@@ -43,7 +43,7 @@ setup(
     zip_safe=False,
     install_requires=INSTALL_REQUIRES,
     tests_require=TESTS_REQUIRE,
-    packages=find_packages(exclude=['tests', 'tests.*', 'examples']),
+    packages=find_packages(exclude=['tests', 'tests.*', 'examples', 'benchmarks', 'benchmarks.*']),
     test_suite='tests',
 
     classifiers=[
