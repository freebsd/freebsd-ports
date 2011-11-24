--- setup.py.orgi	2011-11-24 22:05:06.191148712 +0000
+++ setup.py	2011-11-24 22:05:37.913149693 +0000
@@ -4,10 +4,10 @@
 import glob
 
 # Directory where idnkit header files are installed.
-idnkit_include_dir = '/usr/local/include'
+idnkit_include_dir = '%%LOCALBASE%%/include'
 
 # Directory where libidnkitlite resides.
-idnkit_library_dir = '/usr/local/lib'
+idnkit_library_dir = '%%LOCALBASE%%/lib'
 
 setup(name='idnkit-python',
       version='2.1',
