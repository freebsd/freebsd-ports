--- serial/tools/list_ports_posix.py.orig	2013-10-12 03:43:18 UTC
+++ serial/tools/list_ports_posix.py
@@ -43,7 +43,7 @@ elif plat[:3] == 'bsd' or  \
         plat[:7] == 'freebsd':
 
     def comports():
-        devices = glob.glob('/dev/cuad*')
+        devices = glob.glob('/dev/cua*[!.init][!.lock]')
         return [(d, d, d) for d in devices]
 
 elif plat[:6] == 'darwin':   # OS X (confirmed)
