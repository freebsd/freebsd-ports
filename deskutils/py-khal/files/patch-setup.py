--- setup.py.orig	2016-01-05 12:53:52 UTC
+++ setup.py
@@ -40,8 +40,6 @@ setup(
     },
     install_requires=requirements,
     extras_require=extra_requirements,
-    setup_requires=['setuptools_scm'],  # not needed when using packages from PyPI
-    use_scm_version={'write_to': 'khal/version.py'},
     classifiers=[
         "Development Status :: 4 - Beta",
         "License :: OSI Approved :: MIT License",
