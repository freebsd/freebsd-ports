--- setup.py.orig	2022-01-14 19:50:00 UTC
+++ setup.py
@@ -72,7 +72,7 @@ setup(
         'Programming Language :: Python :: Implementation :: PyPy',
     ],
     test_suite='tests',
-    tests_require=['pytest<7', 'hypothesis<7'],
+    tests_require=['pytest', 'hypothesis<7'],
     scripts=[],
     setup_requires=pytest_runner,
     ext_modules=extensions,
