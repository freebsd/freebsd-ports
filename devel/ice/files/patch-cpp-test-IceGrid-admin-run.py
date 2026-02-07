--- cpp/test/IceGrid/admin/run.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/IceGrid/admin/run.py
@@ -20,11 +20,14 @@ if len(path) == 0:
 sys.path.append(os.path.join(path[0], "scripts"))
 import TestUtil, IceGridAdmin
 
+dbdir = os.path.join(os.getcwd(), "db")
+
 if not TestUtil.isWin32() and os.getuid() == 0:
-    sys.stdout.write("\n")
-    sys.stdout.write("*** can't run test as root ***\n")
-    sys.stdout.write("\n")
-    sys.exit(0)
+    for root, dirs, files in os.walk(dbdir):
+        os.chown(os.path.join(dbdir, root), 65534, 65534)
+        for f in files:
+            os.chown(os.path.join(dbdir, root, f), 65534, 65534)
+    os.setuid(65534)
 
 testdir = os.getcwd();
 
