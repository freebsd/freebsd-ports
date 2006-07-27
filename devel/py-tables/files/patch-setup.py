--- setup.py.orig	Wed Jul 26 23:43:50 2006
+++ setup.py	Wed Jul 26 23:44:46 2006
@@ -72,8 +72,8 @@
 debug = '--debug' in sys.argv
 
 # Global variables
-lib_dirs = []
-inc_dirs = []
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['%%LOCALBASE%%/include']
 optional_libs = []
 
 default_header_dirs = None
