--- tests/tests_e3/os/process/main_test.py.orig	2025-03-28 13:21:34 UTC
+++ tests/tests_e3/os/process/main_test.py
@@ -51,7 +51,7 @@ def test_run_shebang(caplog):
     """Verify that the parse shebang option works."""
     prog_filename = os.path.join(os.getcwd(), "prog")
     with open(prog_filename, "wb") as f:
-        f.write(b"#!/usr/bin/env python\n")
+        f.write(b"#!/usr/bin/env python%%PYTHON_VER%%\n")
         f.write(b"import sys\n")
         f.write(b'print("running %s" % sys.argv[1])\n')
     e3.os.fs.chmod("a+x", prog_filename)
