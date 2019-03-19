--- setup.py.orig	2019-03-19 12:02:31 UTC
+++ setup.py
@@ -124,8 +124,9 @@ if __name__ == '__main__':
     debug = '--debug' in sys.argv
 
     # Global variables
-    lib_dirs = []
-    inc_dirs = [os.path.join('hdf5-blosc', 'src')]
+    lib_dirs = ['%%LOCALBASE%%/lib']
+    inc_dirs = [os.path.join('hdf5-blosc', 'src'),'%%LOCALBASE%%/include']
+
     optional_libs = []
     data_files = []    # list of data files to add to packages (mainly for DLL's)
 
