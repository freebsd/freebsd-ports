--- waflib/Context.py.orig	2026-06-27 09:53:00.227806000 +0200
+++ waflib/Context.py	2026-06-27 09:53:18.691344000 +0200
@@ -2,9 +2,17 @@
 # encoding: utf-8
 # WARNING! Do not edit! https://waf.io/book/index.html#_obtaining_the_waf_file
 
-import os,re,imp,sys
+import os,re,sys
 from waflib import Utils,Errors,Logs
 import waflib.Node
+
+if sys.hexversion > 0x3040000:
+    import types
+    class imp(object):
+        new_module = lambda x: types.ModuleType(x)
+else:
+    import imp
+
 HEXVERSION=0x2000e00
 WAFVERSION="2.0.14"
 WAFREVISION="907519cab9c1c8c7e4f7d4e468ed6200b9250d58"
