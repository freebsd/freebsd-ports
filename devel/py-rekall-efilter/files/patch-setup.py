--- setup.py.orig	2017-11-05 17:28:30 UTC
+++ setup.py
@@ -54,7 +54,7 @@ setup(name="rekall-efilter",
       package_dir={"efilter": "efilter"},
       install_requires=[
           "python-dateutil > 2",
-          "future==0.16.0",
+          "future>=0.16.0",
           "pytz >= 2011k",
           "six >= 1.4.0"]
 )
