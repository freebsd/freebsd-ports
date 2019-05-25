--- execjs/_external_runtime.py.orig	2019-05-25 16:38:20 UTC
+++ execjs/_external_runtime.py
@@ -251,7 +251,7 @@ def jsc():
 def spidermonkey():
     return ExternalRuntime(
         name="SpiderMonkey",
-        command=["js"],
+        command=["js52"],
         runner_source=_runner_sources.SpiderMonkey,
         tempfile=True
     )
