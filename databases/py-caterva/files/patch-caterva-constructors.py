--- caterva/constructors.py.orig	2022-01-28 12:38:26 UTC
+++ caterva/constructors.py
@@ -34,8 +34,8 @@ def empty(shape, itemsize, **kwargs):
             urlpath: str or None
                 The name of the file to store data.  If `None`, data is stored in-memory.
                 (Default `None`)
-            sequential: bool or None
-                Whether the data is stored sequentially or sparsely (one chunk per file).
+            contiguous: bool or None
+                Whether the data is stored contiguously or sparsely (one chunk per file).
                 If `None`, data is stored sparsely.
             memframe: bool
                 If True, the array is backed by a frame in-memory.  Else, by a super-chunk.
