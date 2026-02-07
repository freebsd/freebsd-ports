--- joblib/externals/loky/backend/context.py.orig	2025-06-01 15:05:29 UTC
+++ joblib/externals/loky/backend/context.py
@@ -247,6 +247,14 @@ def _count_physical_cores():
             cpu_count_physical = _count_physical_cores_win32()
         elif sys.platform == "darwin":
             cpu_count_physical = _count_physical_cores_darwin()
+        elif sys.platform.startswith("freebsd"):
+            cpu_info = subprocess.run(
+                "sysctl -n kern.smp.cores".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
         else:
             raise NotImplementedError(f"unsupported platform: {sys.platform}")
 
