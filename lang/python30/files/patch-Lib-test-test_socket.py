--- Lib/test/test_socket.py.orig	Fri Jul  9 00:27:03 2004
+++ Lib/test/test_socket.py	Fri Jul  9 00:27:11 2004
@@ -289,7 +289,7 @@
         # Find one service that exists, then check all the related interfaces.
         # I've ordered this by protocols that have both a tcp and udp
         # protocol, at least for modern Linuxes.
-        for service in ('echo', 'daytime', 'domain'):
+        for service in ('daytime', 'domain'):
             try:
                 port = socket.getservbyname(service, 'tcp')
                 break
