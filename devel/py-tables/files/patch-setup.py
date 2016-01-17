--- setup.py.orig	2015-09-22 03:02:05 UTC
+++ setup.py
@@ -127,8 +127,8 @@ VERSION = open('VERSION').read().strip()
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = ['c-blosc/hdf5']
+lib_dirs = ['/usr/local/lib']
+inc_dirs = ['c-blosc/hdf5','/usr/local/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
