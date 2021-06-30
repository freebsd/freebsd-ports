Fix runtime errors with Python 3.8+ because the function time.clock() has been
removed in Python 3.8, after having been deprecated since Python 3.3.

Obtained from:
https://github.com/shlomif/PySolFC/commit/0961401105850a18ff129e2c25cfffae45a81752

--- pysollib/mfxutil.py.orig	2021-06-09 18:23:28 UTC
+++ pysollib/mfxutil.py
@@ -143,7 +143,11 @@ def getprefdir(package):


 # high resolution clock() and sleep()
-uclock = time.clock
+try:
+    uclock = time.perf_counter
+except Exception:
+    uclock = time.clock
+
 usleep = time.sleep
 if os.name == "posix":
     uclock = time.time
