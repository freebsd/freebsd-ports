--- setup.py.orig	2026-09-29 06:01:10 UTC
+++ setup.py
@@ -157,7 +157,7 @@ setup(
     url='https://pygeoapi.io',
     python_requires='>=3.12',
     install_requires=read('requirements.txt').splitlines(),
-    packages=find_packages(exclude=['pygeoapi.tests']),
+    packages=find_packages(exclude = ["tests", "tests.*"]),
     include_package_data=True,
     entry_points={
         'console_scripts': [
