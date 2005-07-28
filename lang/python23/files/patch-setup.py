--- setup.py.orig	Wed Oct 22 05:01:21 2003
+++ setup.py	Wed Dec  1 23:07:00 2004
@@ -15,7 +15,7 @@
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -770,7 +770,7 @@
             # Linux-specific modules
             exts.append( Extension('linuxaudiodev', ['linuxaudiodev.c']) )
 
-        if platform in ('linux2', 'freebsd4'):
+        if platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6', 'freebsd7'):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
 
         if platform == 'sunos5':
@@ -1140,7 +1140,7 @@
           ext_modules=[Extension('struct', ['structmodule.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle']
+          scripts = []
         )
 
 # --install-platlib
