--- setup.py.orig	Fri May 23 02:36:54 2003
+++ setup.py	Fri Aug  1 03:23:45 2003
@@ -12,7 +12,7 @@
 from distutils.command.install import install
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_tkinter", "gdbm", "mpz", "pyexpat"]
 
 def find_file(filename, std_dirs, paths):
     """Searches for the directory where a given file is located,
@@ -808,7 +808,7 @@
           ext_modules=[Extension('struct', ['structmodule.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc']
+          scripts = []
         )
 
 # --install-platlib
