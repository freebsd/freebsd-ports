--- setup.py.orig	2015-07-05 14:52:30.439427615 +0800
+++ setup.py	2015-07-05 14:53:35.680492890 +0800
@@ -127,8 +127,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = ['c-blosc/hdf5']
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['c-blosc/hdf5','%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
