--- setup.py.orig	Fri Dec 28 06:51:02 2001
+++ setup.py	Fri Jul  4 18:38:23 2003
@@ -14,7 +14,7 @@
 from distutils.command.build_ext import build_ext
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_tkinter", "gdbm", "mpz", "pyexpat"]
 
 def find_file(filename, std_dirs, paths):
     """Searches for the directory where a given file is located,
@@ -609,7 +609,7 @@
           ext_modules=[Extension('struct', ['structmodule.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc']
+          scripts = []
         )
 
 # --install-platlib
