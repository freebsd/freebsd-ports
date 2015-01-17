--- setup.py.orig	2012-04-04 20:27:16 UTC
+++ setup.py
@@ -16,7 +16,7 @@ setup(  
                      open("CHANGES.txt").read(),
     author='Laurence Rowe',
     url='https://github.com/lrowe/experimental.cssselect',
-    packages=find_packages('src'),
+    packages=['experimental'],
     package_dir={'':'src'},
     namespace_packages=[
         '.'.join(name.split('.')[:n+1]) for n in range(name.count('.'))],
