--- setup.py.orig	2017-04-12 12:02:34 UTC
+++ setup.py
@@ -115,8 +115,8 @@ with open('VERSION') as fd:
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = [os.path.join('hdf5-blosc', 'src')]
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = [os.path.join('hdf5-blosc', 'src'),'%%LOCALBASE%%/include']
 optional_libs = []
 data_files = []    # list of data files to add to packages (mainly for DLL's)
 
