--- tests/test_persistency.py.orig	2022-01-28 12:38:26 UTC
+++ tests/test_persistency.py
@@ -12,7 +12,7 @@ import numpy as np
 import os
 
 
-@pytest.mark.parametrize("sequencial",
+@pytest.mark.parametrize("contiguous",
                          [
                              True,
                              False,
@@ -23,14 +23,14 @@ import os
                              ([20, 134, 13], [7, 22, 5], [3, 5, 3], "test01.cat", np.int32),
                              ([12, 13, 14, 15, 16], [4, 6, 4, 7, 5], [2, 4, 2, 3, 3], "test02.cat", np.float32)
                          ])
-def test_persistency(shape, chunks, blocks, urlpath, sequencial, dtype):
+def test_persistency(shape, chunks, blocks, urlpath, contiguous, dtype):
     if os.path.exists(urlpath):
         cat.remove(urlpath)
 
     size = int(np.prod(shape))
     nparray = np.arange(size, dtype=dtype).reshape(shape)
     _ = cat.asarray(nparray, chunks=chunks, blocks=blocks,
-                    urlpath=urlpath, sequencial=sequencial)
+                    urlpath=urlpath, contiguous=contiguous)
     b = cat.open(urlpath)
 
     bc = b[:]
