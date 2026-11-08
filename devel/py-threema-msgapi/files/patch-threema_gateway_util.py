Description: Python 3.14 support for the blocking API (aio_run,
  aio_run_proxy, the threema-gateway CLI).
  - asyncio.get_event_loop() raises RuntimeError on 3.14 when no loop is
    set: fall back to a new loop as upstream fd9e9f38 does, but also
    install it with set_event_loop() so later calls reuse it (otherwise
    the blocking Connection's aiohttp session, created on one loop, is
    used from another and fails with "Timeout context manager should be
    used inside a task").
  - functools.partial is a method descriptor on 3.14: wrap the proxied
    methods in staticmethod() so the instance is not passed twice.
  - asyncio.iscoroutinefunction() is deprecated (removal in 3.16): use
    inspect.iscoroutinefunction().
Issue ID: https://github.com/threema-ch/threema-msgapi-sdk-python/pull/80
Changeset: https://github.com/threema-ch/threema-msgapi-sdk-python/commit/fd9e9f38080a14b40ca037b34338607bd1a5d734
  (partial; set_event_loop, staticmethod and inspect changes are local)
TODO: Submit 0003/0004 and the inspect change upstream; drop once a release
  includes them.

--- threema/gateway/util.py.orig	2024-08-20 20:42:22 UTC
+++ threema/gateway/util.py
@@ -327,7 +327,7 @@ def async_ttl_cache(ttl):
     """
     def _decorator(func):
         # Ensure it is a coroutine
-        if not asyncio.iscoroutinefunction(func):
+        if not inspect.iscoroutinefunction(func):
             raise ValueError('Function is not a coroutine')
 
         # Cache storage
@@ -401,7 +401,11 @@ def aio_run(func):
         print(result)
     """
     def _wrapper(*args, **kwargs):
-        loop = asyncio.get_event_loop()
+        try:
+            loop = asyncio.get_event_loop()
+        except RuntimeError:
+            loop = asyncio.new_event_loop()
+            asyncio.set_event_loop(loop)
         return loop.run_until_complete(func(*args, **kwargs))
     return functools.update_wrapper(_wrapper, func)
 
@@ -441,7 +445,11 @@ def aio_run_proxy(cls):
     class _AioRunProxyDecoratorFactory(wrapt.ObjectProxy):
         def __call__(self, *args, **kwargs):
             # Create the instance while an event loop is running
-            loop = asyncio.get_event_loop()
+            try:
+                loop = asyncio.get_event_loop()
+            except RuntimeError:
+                loop = asyncio.new_event_loop()
+                asyncio.set_event_loop(loop)
             if loop.is_running():
                 instance = cls(*args, **kwargs)
             else:
@@ -471,7 +479,7 @@ def aio_run_proxy(cls):
                         return method(*args_, **kwargs_)
 
                     _method = functools.partial(_method, instance, name)
-                    setattr(_AioRunProxy, name, _method)
+                    setattr(_AioRunProxy, name, staticmethod(_method))
 
                 return _AioRunProxy(instance)
             else:
