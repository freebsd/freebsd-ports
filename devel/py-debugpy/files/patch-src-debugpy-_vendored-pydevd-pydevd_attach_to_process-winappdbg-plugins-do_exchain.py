--- src/debugpy/_vendored/pydevd/pydevd_attach_to_process/winappdbg/plugins/do_exchain.py.orig	2021-09-26 20:11:29 UTC
+++ src/debugpy/_vendored/pydevd/pydevd_attach_to_process/winappdbg/plugins/do_exchain.py
@@ -37,8 +37,8 @@ from winappdbg import HexDump, Table
 def do(self, arg):
     ".exchain - Show the SEH chain"
     thread = self.get_thread_from_prefix()
-    print "Exception handlers for thread %d" % thread.get_tid()
-    print
+    print("Exception handlers for thread %d" % thread.get_tid())
+    print()
     table = Table()
     table.addRow("Block", "Function")
     bits = thread.get_bits()
@@ -48,4 +48,4 @@ def do(self, arg):
         if seh_func is not None:
             seh_func = HexDump.address(seh_func, bits)
         table.addRow(seh, seh_func)
-    print table.getOutput()
+    print(table.getOutput())
