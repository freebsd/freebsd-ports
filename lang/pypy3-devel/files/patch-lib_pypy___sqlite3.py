--- lib_pypy/_sqlite3.py.bak	2013-12-15 23:45:52.000000000 +0200
+++ lib_pypy/_sqlite3.py	2013-12-16 12:07:57.000000000 +0200
@@ -269,11 +269,14 @@
     _ffi.cdef("int sqlite3_enable_load_extension(sqlite3 *db, int onoff);")
 
 if sys.platform.startswith('freebsd'):
+    import os
+    import os.path
+    _localbase = os.environ.get('LOCALBASE', '/usr/local')
     _lib = _ffi.verify("""
     #include <sqlite3.h>
     """, libraries=['sqlite3'],
-         include_dirs=['/usr/local/include'],
-         library_dirs=['/usr/local/lib']
+         include_dirs=[os.path.join(_localbase, 'include')],
+         library_dirs=[os.path.join(_localbase, 'lib')]
     )
 else:
     _lib = _ffi.verify("""
