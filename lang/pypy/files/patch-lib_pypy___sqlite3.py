--- lib_pypy/_sqlite3.py.orig	2013-05-18 16:20:00.000000000 +0200
+++ lib_pypy/_sqlite3.py	2013-05-18 16:21:06.000000000 +0200
@@ -270,7 +270,7 @@
 
 _lib = _ffi.verify("""
 #include <sqlite3.h>
-""", libraries=['sqlite3']
+""", libraries=['sqlite3'], include_dirs=['/usr/local/include'], library_dirs=['/usr/local/lib']
 )
 
 exported_sqlite_symbols = [
