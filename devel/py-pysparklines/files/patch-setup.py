--- setup.py.orig	2013-08-22 21:35:52 UTC
+++ setup.py
@@ -15,6 +15,7 @@ setup(
     author_email="redkrieg@gmail.com",
     url="https://github.com/RedKrieg/pysparklines",
     packages=find_packages(),
+    data_files=[("man/man1", ["man/sparkline.1"])],
     entry_points={
         'console_scripts': [
             'sparkline = sparkline:main',
