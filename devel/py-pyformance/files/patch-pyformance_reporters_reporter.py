Description: Thread.setDaemon() is deprecated since Python 3.10; set the
  daemon attribute instead.
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits since 2018-12); keep locally.

--- pyformance/reporters/reporter.py.orig	2017-10-08 11:44:59 UTC
+++ pyformance/reporters/reporter.py
@@ -8,7 +8,7 @@ class Reporter(object):
     def create_thread(self):
         # noinspection PyAttributeOutsideInit
         self._loop_thread = Thread(target=self._loop, name="pyformance reporter {0}".format(get_qualname(type(self))))
-        self._loop_thread.setDaemon(True)
+        self._loop_thread.daemon = True
 
     def __init__(self, registry=None, reporting_interval=30, clock=None):
         self.registry = registry or global_registry()
