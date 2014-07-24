--- ./src/__init__.py.orig	2014-07-08 19:24:25.000000000 +0800
+++ ./src/__init__.py	2014-07-08 19:24:45.000000000 +0800
@@ -758,7 +758,7 @@
                 ret_code = self.p.poll()
                 if debug:
                     print "ret_code: " + str(ret_code)
-                if ret_code != None:
+                if ret_code not in (None, 0):
                     if debug:
                         print "NOOOOO"
                     print "subprocess died with return code: " + repr(ret_code)
