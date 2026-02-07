--- asrun/system.py.orig	2017-07-13 07:40:52 UTC
+++ asrun/system.py
@@ -133,10 +133,10 @@ def get_system_tmpdir():
        or os.environ.get('TEMP') or os.environ.get('TMP')
     if var:
         return var
-    if on_linux():
-        return "/tmp"
-    else:
+    if on_windows():
         return osp.join(os.environ.get("%systemroot%", "c:\\windows"), "temp")
+    else:
+        return "/tmp"
 
 
 def split_path(path):
@@ -854,6 +854,8 @@ class AsterSystem:
                     num = max([int(i) for i in l_ids]) + 1
             elif on_windows():
                 num = 1
+            else:
+                num = %%MAKE_JOBS_NUMBER%%
             self._cpuinfo_cache[what+mach+user] = num
             self._dbg("GetCpuInfo '%s' returns : %s" % (what, num))
             return num
