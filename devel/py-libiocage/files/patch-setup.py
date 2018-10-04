--- setup.py.orig	2018-10-04 10:36:15 UTC
+++ setup.py
@@ -94,7 +94,6 @@ setup(
     include_package_data=True,
     install_requires=iocage_requirements["install_requires"],
     dependency_links=iocage_requirements["dependency_links"],
-    setup_requires=['pytest-runner'],
     tests_require=['pytest', 'pytest-cov', 'pytest-pep8']
 )
 
