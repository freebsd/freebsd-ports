--- setup.py.orig	Fri Mar  2 07:24:14 2001
+++ setup.py	Mon Mar  5 15:26:17 2001
@@ -14,7 +14,7 @@
 from distutils.command.build_ext import build_ext
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_tkinter", "gdbm", "mpz", "pyexpat"]
 
 def find_file(filename, std_dirs, paths):
     """Searches for the directory where a given file is located,
