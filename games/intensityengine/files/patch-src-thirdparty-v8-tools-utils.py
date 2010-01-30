--- src/thirdparty/v8/tools/utils.py.orig	2010-01-28 22:56:11.000000000 +0300
+++ src/thirdparty/v8/tools/utils.py	2010-01-29 00:11:53.000000000 +0300
@@ -67,6 +67,8 @@
     return 'arm'
   elif (not id) or (not re.match('(x|i[3-6])86', id) is None):
     return 'ia32'
+  elif id == 'amd64':
+    return 'x64'
   else:
     return None
 
