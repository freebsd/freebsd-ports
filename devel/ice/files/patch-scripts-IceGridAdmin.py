--- scripts/IceGridAdmin.py.orig	2015-07-04 12:59:57.542262997 +0200
+++ scripts/IceGridAdmin.py	2015-07-04 13:02:16.496576997 +0200
@@ -222,11 +222,14 @@
 def iceGridTest(application, additionalOptions = "", applicationOptions = ""):
 
     testdir = os.getcwd()
+    dbdir = os.path.join(os.getcwd(), "db")
+
     if not TestUtil.isWin32() and os.getuid() == 0:
-        print
-        print("*** can't run test as root ***")
-        print
-        return
+        for root, dirs, files in os.walk(dbdir):
+            os.chown(os.path.join(dbdir, root), 65534, 65534)
+            for f in files:
+                os.chown(os.path.join(dbdir, root, f), 65534, 65534)
+        os.setuid(65534)
 
     client = TestUtil.getDefaultClientFile()
     if TestUtil.getDefaultMapping() != "java":
