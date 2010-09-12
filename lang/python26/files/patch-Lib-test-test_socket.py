--- Lib/test/test_socket.py.orig	2010-08-14 16:51:08.542899328 +0800
+++ Lib/test/test_socket.py	2010-08-14 16:53:25.902184941 +0800
@@ -334,7 +334,7 @@
         # I've ordered this by protocols that have both a tcp and udp
         # protocol, at least for modern Linuxes.
         if sys.platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                            'freebsd7', 'freebsd8', 'darwin'):
+                            'freebsd7', 'freebsd8', 'freebsd9', 'darwin'):
             # avoid the 'echo' service on this platform, as there is an
             # assumption breaking non-standard port/protocol entry
             services = ('daytime', 'qotd', 'domain')
