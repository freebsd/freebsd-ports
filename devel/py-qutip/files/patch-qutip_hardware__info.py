Same as https://github.com/qutip/qutip/pull/895, but the PR patch doesn't merge with this version

--- qutip/hardware_info.py.orig	2018-05-09 07:35:04 UTC
+++ qutip/hardware_info.py
@@ -85,6 +85,14 @@ def _linux_hardware_info():
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
@@ -118,6 +126,8 @@ def hardware_info():
         out = _win_hardware_info()
     elif sys.platform in ['linux', 'linux2']:
         out = _linux_hardware_info()
+    elif sys.platform.startswith('freebsd'):
+        out = _freebsd_hardware_info()
     else:
         out = {}
     return out
