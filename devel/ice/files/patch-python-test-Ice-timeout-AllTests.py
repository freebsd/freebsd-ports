--- python/test/Ice/timeout/AllTests.py.orig	2019-08-12 19:54:18 UTC
+++ python/test/Ice/timeout/AllTests.py
@@ -249,9 +249,9 @@ def allTests(communicator):
     comm = Ice.initialize(initData)
     connection = comm.stringToProxy(sref).ice_getConnection();
     timeout.holdAdapter(800);
-    now = time.clock();
+    now = time.perf_counter();
     comm.destroy();
-    test((time.clock() - now) < 0.7);
+    test((time.perf_counter() - now) < 0.7);
 
     print("ok")
 
