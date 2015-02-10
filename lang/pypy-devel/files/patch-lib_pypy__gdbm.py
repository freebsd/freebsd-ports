--- lib_pypy/gdbm.py.orig	2015-02-10 20:14:29.243203718 +0200
+++ lib_pypy/gdbm.py	2015-02-10 20:17:23.235080307 +0200
@@ -1,4 +1,4 @@
-import cffi, os
+import cffi, os, sys
 
 ffi = cffi.FFI()
 ffi.cdef('''
@@ -37,9 +37,19 @@
 ''')
 
 try:
-    lib = ffi.verify('''
-    #include "gdbm.h"
-    ''', libraries=['gdbm'])
+    if sys.platform.startswith('freebsd'):
+        import os.path
+        _localbase = os.environ.get('LOCALBASE', '/usr/local')
+        lib = ffi.verify('''
+        #include "gdbm.h"
+        ''', libraries=['gdbm'],
+             include_dirs=[os.path.join(_localbase, 'include')],
+             library_dirs=[os.path.join(_localbase, 'lib')]
+        )
+    else:
+        lib = ffi.verify('''
+        #include "gdbm.h"
+        ''', libraries=['gdbm'])
 except cffi.VerificationError as e:
     # distutils does not preserve the actual message,
     # but the verification is simple enough that the
