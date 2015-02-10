--- pypy/sandbox/pypy_interact.py.orig	2014-05-08 18:36:08.000000000 +0200
+++ pypy/sandbox/pypy_interact.py	2014-05-12 20:20:57.000000000 +0200
@@ -22,11 +22,14 @@
 
 import sys, os
 sys.path.insert(0, os.path.realpath(os.path.join(os.path.dirname(__file__), '..', '..')))
+from pypy.module.sys.version import PYPY_VERSION
 from rpython.translator.sandbox.sandlib import SimpleIOSandboxedProc
 from rpython.translator.sandbox.sandlib import VirtualizedSandboxedProc
 from rpython.translator.sandbox.vfs import Dir, RealDir, RealFile
 import pypy
 LIB_ROOT = os.path.dirname(os.path.dirname(pypy.__file__))
+LIB_ROOT = os.path.join(LIB_ROOT, 'lib')
+LIB_ROOT = os.path.join(LIB_ROOT, 'pypy-%d.%d' % PYPY_VERSION[:2])
 
 class PyPySandboxedProc(VirtualizedSandboxedProc, SimpleIOSandboxedProc):
     argv0 = '/bin/pypy-c'
@@ -56,10 +59,10 @@
         return Dir({
             'bin': Dir({
                 'pypy-c': RealFile(self.executable, mode=0111),
-                'lib-python': RealDir(os.path.join(libroot, 'lib-python'),
-                                      exclude=exclude), 
-                'lib_pypy': RealDir(os.path.join(libroot, 'lib_pypy'),
-                                      exclude=exclude),
+                'lib': Dir({
+                    'pypy-%d.%d' % PYPY_VERSION[:2] : RealDir(libroot, 
+                                                             exclude=exclude)
+                    })
                 }),
              'tmp': tmpdirnode,
              })
