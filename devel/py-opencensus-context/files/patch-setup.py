--- setup.py.orig	2022-08-03 21:31:16 UTC
+++ setup.py
@@ -54,7 +54,7 @@ setup(
     ],
     extras_require={},
     license='Apache-2.0',
-    packages=find_packages(exclude=('examples', 'tests',)),
+    packages=['opencensus.common.runtime_context'],
     namespace_packages=[],
     url='https://github.com/census-instrumentation/opencensus-python/tree/master/context/opencensus-context',  # noqa: E501
     zip_safe=False,
