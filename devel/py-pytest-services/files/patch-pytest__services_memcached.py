--- pytest_services/memcached.py.orig	2025-07-16 00:29:03 UTC
+++ pytest_services/memcached.py
@@ -14,9 +14,15 @@ def memcached(request, run_services, memcached_socket,
 def memcached(request, run_services, memcached_socket, watcher_getter):
     """The memcached instance which is ready to be used by the tests."""
     if run_services:
+        try:
+            user=os.environ['USER']
+            arguments=['-u', user]
+        except KeyError:
+            arguments=[]
+        arguments.extend(['-s', memcached_socket])
         return watcher_getter(
             name='memcached',
-            arguments=['-s', memcached_socket],
+            arguments=arguments,
             checker=lambda: os.path.exists(memcached_socket),
             request=request,
         )
