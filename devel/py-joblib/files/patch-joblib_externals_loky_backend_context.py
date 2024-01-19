--- joblib/externals/loky/backend/context.py.orig	2023-06-29 15:14:21 UTC
+++ joblib/externals/loky/backend/context.py
@@ -245,6 +245,9 @@ def _count_physical_cores():
         return physical_cores_cache, exception
 
     # Not cached yet, find it
+    # Using subprocesses is inefficient, but python has no portable
+    # sysctl interface at this time
+    # FIXME: Add OpenBSD, Dragonfly
     try:
         if sys.platform == "linux":
             cpu_info = subprocess.run(
@@ -269,6 +272,26 @@ def _count_physical_cores():
         elif sys.platform == "darwin":
             cpu_info = subprocess.run(
                 "sysctl -n hw.physicalcpu".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
+        elif sys.platform.startswith('freebsd'):
+            cpu_info = subprocess.run(
+                "sysctl -n kern.smp.cores".split(),
+                capture_output=True,
+                text=True,
+            )
+            cpu_info = cpu_info.stdout
+            cpu_count_physical = int(cpu_info)
+        elif sys.platform.startswith('netbsd'):
+            # FIXME: hw.ncpu reports the number of hyperthreads.
+            # We prefer independent cores to prevent oversubscription.
+            # NetBSD does not currently expose physical core counts,
+            # but this is under discussion in PR kern/57816.
+            cpu_info = subprocess.run(
+                "sysctl -n hw.ncpu".split(),
                 capture_output=True,
                 text=True,
             )
