--- build/detect_host_arch.py.orig	2023-03-30 00:33:39 UTC
+++ build/detect_host_arch.py
@@ -20,6 +20,8 @@ def HostArch():
     host_arch = 'ia32'
   elif host_arch in ['x86_64', 'amd64']:
     host_arch = 'x64'
+  elif host_arch.startswith('arm64'):
+    host_arch = 'arm64'
   elif host_arch.startswith('arm'):
     host_arch = 'arm'
   elif host_arch.startswith('aarch64'):
