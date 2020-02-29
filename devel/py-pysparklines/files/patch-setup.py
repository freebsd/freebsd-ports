--- setup.py.orig	2020-02-22 20:09:57 UTC
+++ setup.py
@@ -15,6 +15,7 @@ setuptools.setup(
     author_email="redkrieg@gmail.com",
     url="https://github.com/RedKrieg/pysparklines",
     packages=setuptools.find_packages(),
+    data_files=[("man/man1", ["man/sparkline.1"])],
     entry_points={
         'console_scripts': [
             'sparkline = sparkline:main',
