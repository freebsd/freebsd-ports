--- setup.py.orig	Wed Aug  4 11:22:03 2004
+++ setup.py	Wed Aug  4 11:22:48 2004
@@ -66,7 +66,7 @@
 data.extend(glob.glob('images/*.ppm'))
 data.append('.matplotlibrc')
 
-data_files=[('share/matplotlib', data),]
+data_files=[('share/py-matplotlib', data),]
 
 cxx = glob.glob('CXX/*.cxx')
 cxx.extend(glob.glob('CXX/*.c'))
