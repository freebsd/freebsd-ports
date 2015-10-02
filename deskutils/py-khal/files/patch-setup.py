--- setup.py.orig	2015-08-22 23:17:24 UTC
+++ setup.py
@@ -41,8 +41,6 @@ setup(
     },
     install_requires=requirements,
     extras_require=extra_requirements,
-    setup_requires=['setuptools_scm'],
-    use_scm_version={'write_to': 'khal/version.py'},
     classifiers=[
         "Development Status :: 4 - Beta",
         "License :: OSI Approved :: MIT License",
