Drop after devel/py-pytest >= 8.3 update

E       TypeError: importorskip() got an unexpected keyword argument 'exc_type'

--- tests/test_schedulers.py.orig	2024-11-24 19:38:57 UTC
+++ tests/test_schedulers.py
@@ -1248,7 +1248,7 @@ class TestGeventScheduler(SchedulerImplementationTestB
     @pytest.fixture
     def scheduler(self):
         gevent = pytest.importorskip(
-            "apscheduler.schedulers.gevent", exc_type=ImportError
+            "apscheduler.schedulers.gevent",
         )
         return gevent.GeventScheduler()
 
