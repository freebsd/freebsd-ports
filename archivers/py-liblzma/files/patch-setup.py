--- setup.py~	2009-01-12 14:38:38.000000000 +0200
+++ setup.py	2009-01-12 15:03:21.000000000 +0200
@@ -23,7 +23,7 @@
 #
 import sys, os
 from warnings import warn
-from setuptools import setup, Extension
+from distutils.core import setup, Extension
 
 descr = "Python bindings for liblzma"
 long_descr = """PylibLZMA provides a python interface for the liblzma library
@@ -54,6 +54,8 @@
 pc_libs = subprocess.Popen("pkg-config --libs liblzma", shell=True, stdout=subprocess.PIPE, close_fds=True).stdout.readline().strip()
 if(pc_libs):
 	link_args.extend(pc_libs.split(' '))
+link_args.append('-L%s/lib' % os.environ["LOCALBASE"])
+link_args.append('-lpython%i.%i' % sys.version_info[:2])
 
 extens=[Extension('lzma', c_files, extra_compile_args=compile_args, extra_link_args=link_args, define_macros=version_define)]
 
@@ -74,7 +76,6 @@
     ],
     py_modules = modules,
     ext_modules = extens,
-    test_suite = 'tests',
 )
 
 sys.exit(0)
