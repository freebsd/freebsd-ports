--- usbtmc/usbtmc.py.orig	2017-01-18 05:35:14 UTC
+++ usbtmc/usbtmc.py
@@ -841,7 +841,7 @@
             raise NotImplementedError()
 
     def _release_kernel_driver(self, interface_number):
-        if os.name == 'posix':
+        if os.name == 'posix' and os.uname()[0] != 'FreeBSD':
             if self.device.is_kernel_driver_active(interface_number):
                 self.reattach.append(interface_number)
                 try:
