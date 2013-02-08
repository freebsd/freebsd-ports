--- setup.py.orgi	2013-01-12 11:23:31.000000000 +0100
+++ setup.py	2013-01-12 11:24:12.000000000 +0100
@@ -4,10 +4,10 @@
 import glob
 
 # Directory where idnkit header files are installed.
-idnkit_include_dir = '/usr/local/include'
+idnkit_include_dir = '%%LOCALBASE%%/include'
 
 # Directory where libidnkitlite resides.
-idnkit_library_dir = '/usr/local/lib'
+idnkit_library_dir = '%%LOCALBASE%%/lib'
 
 setup(name='idnkit-python',
       version='2.2',
