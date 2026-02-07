--- setup.py.orig	2023-10-06 08:01:07 UTC
+++ setup.py
@@ -34,7 +34,7 @@ setup(
     long_description=read('README.rst'),
     py_modules=['pytest_azurepipelines'],
     python_requires='>=3.5',
-    data_files=[('resources', ['resources/style.css'])],
+    package_data={'resources': ['resources/style.css']},
     install_requires=['importlib-resources', 'pytest>=5.0.0', 'pytest-nunit>=1.0.0,<2.0.0'],
     classifiers=[
         'Development Status :: 5 - Production/Stable',
