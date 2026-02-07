--- raphodo/utilities.py.orig	2020-05-03 17:31:45 UTC
+++ raphodo/utilities.py
@@ -83,10 +83,11 @@ if arrow_version >= parse_version('0.14.3') and arrow_
 # Linux specific code to ensure child processes exit when parent dies
 # See http://stackoverflow.com/questions/19447603/
 # how-to-kill-a-python-child-process-created-with-subprocess-check-output-when-t/
-libc = ctypes.CDLL("libc.so.6")
+libc = ctypes.CDLL("libc.so.7")
 def set_pdeathsig(sig = signal.SIGTERM):
     def callable():
-        return libc.prctl(1, sig)
+        return 0
+        #return libc.procctl(0, 0, 11, sig)
     return callable
 
 
