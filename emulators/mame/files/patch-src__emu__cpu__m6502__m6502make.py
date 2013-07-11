--- src/emu/cpu/m6502/m6502make.py.orig
+++ src/emu/cpu/m6502/m6502make.py
@@ -14,7 +14,7 @@
     opcodes = []
     logging.info("load_opcodes: %s", fname)
     try:
-        f = open(fname, "r")
+        f = open(fname, "rU")
     except Exception, err:
         logging.error("cannot read opcodes file %s [%s]", fname, err)
         sys.exit(1)
@@ -36,7 +36,7 @@
     logging.info("load_disp: %s", fname)
     states = []
     try:
-        f = open(fname, "r")
+        f = open(fname, "rU")
     except Exception, err:
         logging.error("cannot read display file %s [%s]", fname, err)
         sys.exit(1)
