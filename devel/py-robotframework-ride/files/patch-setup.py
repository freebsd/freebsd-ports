--- setup.py.orig	2019-06-28 07:27:57 UTC
+++ setup.py
@@ -47,8 +47,8 @@ Programming Language :: Python
 Topic :: Software Development :: Testing
 """.strip().splitlines()
 
-with open(join(ROOT_DIR, 'requirements.txt')) as f:
-    REQUIREMENTS = f.read().splitlines()
+#with open(join(ROOT_DIR, 'requirements.txt')) as f:
+#    REQUIREMENTS = f.read().splitlines()
 
 # This solution is found at http://stackoverflow.com/a/26490820/5889853
 from setuptools.command.install import install
@@ -75,7 +75,7 @@ setup(
     author_email='robotframework@gmail.com',
     url='https://github.com/robotframework/RIDE/',
     download_url='https://pypi.python.org/pypi/robotframework-ride',
-    install_requires = REQUIREMENTS,
+#    install_requires = REQUIREMENTS,
     package_dir={'': SOURCE_DIR},
     packages=find_packages(SOURCE_DIR),
     package_data=package_data,
@@ -84,5 +84,5 @@ setup(
     options={'install': {'force': True}},
     scripts=['src/bin/ride.py', 'src/bin/ride_postinstall.py'],
     cmdclass={'install': CustomInstallCommand},
-    requires=['Pygments', 'wxPython', 'PyPubSub']
+    requires=['Pygments', 'wxPython']
 )
