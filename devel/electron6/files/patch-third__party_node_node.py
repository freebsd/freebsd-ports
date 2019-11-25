--- third_party/node/node.py.orig	2019-09-10 10:43:18 UTC
+++ third_party/node/node.py
@@ -12,6 +12,7 @@ import sys
 def GetBinaryPath():
   return os_path.join(os_path.dirname(__file__), *{
     'Darwin': ('mac', 'node-darwin-x64', 'bin', 'node'),
+    'FreeBSD': ('freebsd', 'node-freebsd-x64', 'bin', 'node'),
     'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
     'Windows': ('win', 'node.exe'),
   }[platform.system()])
