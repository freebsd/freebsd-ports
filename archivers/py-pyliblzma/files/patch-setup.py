# allow building without pkg-config
# https://bugs.launchpad.net/pyliblzma/+bug/613837
# https://bazaar.launchpad.net/~proyvind/pyliblzma/trunk/revision/494

--- setup.py.orig	2010-04-13 21:06:43 UTC
+++ setup.py
@@ -24,6 +24,7 @@
 import sys, os, subprocess
 from warnings import warn
 from setuptools import setup, Extension
+from distutils.ccompiler import get_default_compiler
 
 descr = "Python bindings for liblzma"
 long_descr = """PylibLZMA provides a python interface for the liblzma library
@@ -41,21 +42,26 @@ for i in xrange(len(c_files)):
     c_files[i] = os.path.join('src', c_files[i])
 
 compile_args = []
-warnflags = ['-Wall', '-Wextra', '-pedantic', '-Wswitch-enum', '-Wswitch-default']
-compile_args.extend(warnflags)
 link_args = []
-if not subprocess.Popen('touch gnu99-test.c; gcc -std=gnu99 -E gnu99-test.c > /dev/null; rm -f gnu99-test.c',
-		shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, close_fds=True).stdout.read():
-    compile_args.append('-std=gnu99')
+libraries = ['lzma']
 
-pc_cflags = subprocess.Popen("pkg-config --cflags liblzma", shell=True, stdout=subprocess.PIPE, close_fds=True).stdout.readline().strip()
-if(pc_cflags):
-	compile_args.extend(pc_cflags.split(' '))
-pc_libs = subprocess.Popen("pkg-config --libs liblzma", shell=True, stdout=subprocess.PIPE, close_fds=True).stdout.readline().strip()
-if(pc_libs):
-	link_args.extend(pc_libs.split(' '))
+if get_default_compiler() in ('cygwin', 'emx', 'mingw32', 'unix'):
+    warnflags = ['-Wall', '-Wextra', '-pedantic', '-Wswitch-enum', '-Wswitch-default']
+    compile_args.extend(warnflags)
 
-extens=[Extension('lzma', c_files, extra_compile_args=compile_args, extra_link_args=link_args, define_macros=version_define)]
+    if not subprocess.Popen('touch gnu99-test.c; gcc -std=gnu99 -E gnu99-test.c > /dev/null; rm -f gnu99-test.c',
+            shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, close_fds=True).stdout.read():
+        compile_args.append('-std=gnu99')
+    
+    pc_cflags = subprocess.Popen("pkg-config --cflags liblzma", shell=True, stdout=subprocess.PIPE, close_fds=True).stdout.readline().strip()
+    if(pc_cflags):            
+        compile_args.extend(pc_cflags.split(' '))
+
+    pc_libs = subprocess.Popen("pkg-config --libs liblzma", shell=True, stdout=subprocess.PIPE, close_fds=True).stdout.readline().strip()
+    if(pc_libs):
+        link_args.extend(pc_libs.split(b' '))
+
+extens=[Extension('lzma', c_files, extra_compile_args=compile_args, libraries=libraries, extra_link_args=link_args, define_macros=version_define)]
 
 setup(
     name = "pyliblzma",
