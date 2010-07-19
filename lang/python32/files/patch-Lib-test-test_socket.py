--- Lib/test/test_socket.py.orig	2009-10-04 10:54:52.000000000 -0400
+++ Lib/test/test_socket.py	2010-06-24 13:57:37.000000000 -0400
@@ -337,7 +337,7 @@
         # I've ordered this by protocols that have both a tcp and udp
         # protocol, at least for modern Linuxes.
         if sys.platform in ('linux2', 'freebsd4', 'freebsd5', 'freebsd6',
-                            'freebsd7', 'freebsd8', 'darwin'):
+                            'freebsd7', 'freebsd8', 'freebsd9', 'darwin'):
             # avoid the 'echo' service on this platform, as there is an
             # assumption breaking non-standard port/protocol entry
             services = ('daytime', 'qotd', 'domain')
