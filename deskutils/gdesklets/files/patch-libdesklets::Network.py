--- libdesklets/Network.py.orig	Mon Feb 23 11:01:31 2004
+++ libdesklets/Network.py	Mon Feb 23 11:01:55 2004
@@ -142,7 +142,7 @@
         
         if ("FreeBSD" == platform or "NetBSD" == platform):
             fd = os.popen("ifconfig -a | grep mtu", "r")
-            data = fs.readlines()
+            data = fd.readlines()
             fd.close()
 
             for lines in data:
