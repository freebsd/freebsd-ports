Same as https://github.com/qutip/qutip/pull/895, but the PR patch doesn't merge with this version

--- qutip/hardware_info.py.orig	2016-12-06 23:45:34 UTC
+++ qutip/hardware_info.py
@@ -80,6 +80,14 @@ def _linux_hardware_info():
     results.update({'os': 'Linux'})
     return results
 
+def _freebsd_hardware_info():
+    results = {}
+    results.update({'cpus': int(os.popen('sysctl -n hw.ncpu').readlines()[0])})
+    results.update({'cpu_freq': int(os.popen('sysctl -n dev.cpu.0.freq').readlines()[0])})
+    results.update({'memsize': int(os.popen('sysctl -n hw.realmem').readlines()[0]) / 1024})
+    # add OS information
+    results.update({'os': 'FreeBSD'})
+    return results
 
 def _win_hardware_info():
     try:
@@ -114,6 +122,8 @@ def hardware_info():
             out = _win_hardware_info()
         elif sys.platform in ['linux', 'linux2']:
             out = _linux_hardware_info()
+        elif sys.platform.startswith('freebsd'):
+            out = _freebsd_hardware_info()
         else:
             out = {}
     except:
