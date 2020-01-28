--- setup.py.orig	2019-11-03 07:18:11 UTC
+++ setup.py
@@ -36,9 +36,6 @@ setup(name="expiringdict",
       include_package_data=True,
       zip_safe=True,
       tests_require=tests_require,
-      install_requires=[
-          "typing",
-      ],
       extras_require={
           "tests": tests_require,
       })
