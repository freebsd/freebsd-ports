--- benchmarks/test_benchmark_init.py.orig	2023-10-04 07:21:13 UTC
+++ benchmarks/test_benchmark_init.py
@@ -1,3 +1,4 @@
+import asyncio
 import random
 import string
 
@@ -20,6 +21,7 @@ async def test_initializing_models(aio_benchmark, num_
             for i in range(0, num_models)
         ]
         assert len(authors) == num_models
+        return asyncio.sleep(0)
 
     await initialize_models(num_models)
 
