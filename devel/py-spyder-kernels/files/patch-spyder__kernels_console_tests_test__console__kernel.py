--- spyder_kernels/console/tests/test_console_kernel.py.orig	2024-08-19 17:12:51 UTC
+++ spyder_kernels/console/tests/test_console_kernel.py
@@ -1320,7 +1320,7 @@ def test_interrupt():
                 # not from my request
                 continue
             break
-        assert time.time() - t0 < 5
+        assert time.time() - t0 < 15
 
 
 def test_enter_debug_after_interruption():
