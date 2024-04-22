--- pnio_dcp/l2socket/__init__.py.orig	2024-02-18 23:35:44 UTC
+++ pnio_dcp/l2socket/__init__.py
@@ -10,5 +10,7 @@ if sys.platform == 'win32':
     L2Socket = L2PcapSocket
 elif sys.platform.startswith('linux'):
     L2Socket = L2LinuxSocket
+elif sys.platform.startswith('freebsd'):
+    L2Socket = L2LinuxSocket
 else:
     raise NotImplementedError(f"Platform {sys.platform} is currently not supported.")
