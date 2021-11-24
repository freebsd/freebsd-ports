--- third_party/node/node.py.orig	2021-07-15 19:14:05 UTC
+++ third_party/node/node.py
@@ -19,6 +19,7 @@ def GetBinaryPath():
                           'node-darwin-arm64', 'bin', 'node'))
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': ('mac', 'node-darwin-x64', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd-x64', 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
