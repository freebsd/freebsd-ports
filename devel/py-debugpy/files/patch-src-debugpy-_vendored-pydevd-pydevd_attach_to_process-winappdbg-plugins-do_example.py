--- src/debugpy/_vendored/pydevd/pydevd_attach_to_process/winappdbg/plugins/do_example.py.orig	2021-09-09 10:13:22 UTC
+++ src/debugpy/_vendored/pydevd/pydevd_attach_to_process/winappdbg/plugins/do_example.py
@@ -34,8 +34,8 @@ __revision__ = "$Id$"
 
 def do(self, arg):
     ".example - This is an example plugin for the command line debugger"
-    print "This is an example command."
-    print "%s.do(%r, %r):" % (__name__, self, arg)
-    print "  last event", self.lastEvent
-    print "  prefix", self.cmdprefix
-    print "  arguments", self.split_tokens(arg)
+    print("This is an example command.")
+    print("%s.do(%r, %r):" % (__name__, self, arg))
+    print("  last event", self.lastEvent)
+    print("  prefix", self.cmdprefix)
+    print("  arguments", self.split_tokens(arg))
