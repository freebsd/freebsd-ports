--- src/bootstrap/bootstrap.py.orig	2021-11-11 14:21:03 UTC
+++ src/bootstrap/bootstrap.py
@@ -283,7 +283,7 @@ def default_build_triple(verbose):
         err = "unknown OS type: {}".format(ostype)
         sys.exit(err)
 
-    if cputype == 'powerpc' and ostype == 'unknown-freebsd':
+    if cputype in ['powerpc', 'riscv'] and ostype == 'unknown-freebsd':
         cputype = subprocess.check_output(
               ['uname', '-p']).strip().decode(default_encoding)
     cputype_mapper = {
