--- setup.py.orig	Wed May 11 11:04:04 2005
+++ setup.py	Wed May 11 11:04:38 2005
@@ -30,8 +30,8 @@
 
 # Global variables
 lflags_arg = []
-lib_dirs = []
-inc_dirs = []
+lib_dirs = ['%%LOCALBASE%%/lib']
+inc_dirs = ['%%LOCALBASE%%/include']
 
 # Some useful functions
 def check_lib_unix(where, libname, headername, compulsory):
