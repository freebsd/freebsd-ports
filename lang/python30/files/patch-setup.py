--- setup.py.orig	Fri Jul 23 11:50:10 2004
+++ setup.py	Sat Aug 21 09:04:58 2004
@@ -15,7 +15,7 @@
 from distutils.command.install_lib import install_lib
 
 # This global variable is used to hold the list of modules to be disabled.
-disabled_module_list = []
+disabled_module_list = ["_bsddb", "_tkinter", "gdbm", "mpz"]
 
 def add_dir_to_list(dirlist, dir):
     """Add the directory 'dir' to the list 'dirlist' (at the front) if
@@ -782,7 +782,7 @@
             # Linux-specific modules
             exts.append( Extension('linuxaudiodev', ['linuxaudiodev.c']) )
 
-        if platform in ('linux2', 'freebsd4', 'freebsd5'):
+        if platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6'):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
 
         if platform == 'sunos5':
@@ -1164,8 +1164,7 @@
           ext_modules=[Extension('struct', ['structmodule.c'])],
 
           # Scripts to install
-          scripts = ['Tools/scripts/pydoc', 'Tools/scripts/idle',
-                     'Lib/smtpd.py']
+          scripts = []
         )
 
 # --install-platlib
