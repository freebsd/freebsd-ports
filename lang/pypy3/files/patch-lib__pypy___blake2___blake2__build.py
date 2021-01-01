--- lib_pypy/_blake2/_blake2_build.py.orig	2020-03-27 16:01:26 UTC
+++ lib_pypy/_blake2/_blake2_build.py
@@ -80,7 +80,7 @@ void* addressof_node_offset(blake_param *S) {
 """
 
 
-_libdir = os.path.abspath(os.path.join(os.path.dirname(__file__), 'impl'))
+_libdir = 'impl'
 if BLAKE2_USE_SSE:
     sourcesB=[os.path.join(_libdir, 'blake2b.c'), ]
     sourcesS=[os.path.join(_libdir, 'blake2s.c'), ]
