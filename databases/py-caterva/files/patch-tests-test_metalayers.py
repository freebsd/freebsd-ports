--- tests/test_metalayers.py.orig	2022-01-28 12:38:26 UTC
+++ tests/test_metalayers.py
@@ -13,7 +13,7 @@ import os
 from msgpack import packb
 
 
-@pytest.mark.parametrize("sequencial",
+@pytest.mark.parametrize("contiguous",
                          [
                              True,
                              False,
@@ -24,7 +24,7 @@ from msgpack import packb
                              ([20, 134, 13], [12, 66, 8], [3, 13, 5], "testmeta01.cat", np.int32),
                              ([12, 13, 14, 15, 16], [8, 9, 4, 12, 9], [2, 6, 4, 5, 4], "testmeta02.cat", np.float32)
                          ])
-def test_metalayers(shape, chunks, blocks, urlpath, sequencial, dtype):
+def test_metalayers(shape, chunks, blocks, urlpath, contiguous, dtype):
     if os.path.exists(urlpath):
         cat.remove(urlpath)
 
@@ -34,7 +34,7 @@ def test_metalayers(shape, chunks, blocks, urlpath, se
     # Create an empty caterva array (on disk)
     itemsize = np.dtype(dtype).itemsize
     a = cat.empty(shape, itemsize, chunks=chunks, blocks=blocks,
-                  urlpath=urlpath, sequencial=sequencial,
+                  urlpath=urlpath, contiguous=contiguous,
                   meta={"numpy": numpy_meta,
                         "test": test_meta})
 
