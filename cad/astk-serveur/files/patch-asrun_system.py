--- ./asrun/system.py.orig	2010-07-07 18:18:08.000000000 +0200
+++ ./asrun/system.py	2010-08-16 20:51:28.000000000 +0200
@@ -137,10 +137,10 @@
     var = os.environ.get("TMPDIR") or os.environ.get('TEMP') or os.environ.get('TMP')
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
@@ -818,6 +818,8 @@
                     num = max([int(i) for i in l_ids]) + 1
             elif on_windows():
                 num = 1
+            else:
+                num = %%MAKE_JOBS_NUMBER%%
             self._cpuinfo_cache[what+mach+user] = num
             self._dbg("GetCpuInfo '%s' returns : %s" % (what, num))
             return num
