--- src/emu/cpu/mcs96/mcs96make.py.orig
+++ src/emu/cpu/mcs96/mcs96make.py
@@ -69,7 +69,7 @@
         self.ea = {}
         self.macros = {}
         try:
-            f = open(fname, "r")
+            f = open(fname, "rU")
         except Exception, err:
             print "Cannot read opcodes file %s [%s]" % (fname, err)
             sys.exit(1)
