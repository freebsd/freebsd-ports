--- setup.py.orig	Sat Aug 21 08:12:35 2004
+++ setup.py	Sat Aug 21 08:12:48 2004
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
+        if platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6'):
             exts.append( Extension('ossaudiodev', ['ossaudiodev.c']) )
 
         if platform == 'sunos5':
