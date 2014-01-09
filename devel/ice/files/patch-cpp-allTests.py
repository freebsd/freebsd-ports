--- cpp.orig/allTests.py	2013-03-11 15:19:58.000000000 +0000
+++ cpp/allTests.py	2013-05-19 22:25:00.000000000 +0000
@@ -62,7 +63,7 @@
     ("Ice/servantLocator", ["core"]),
     ("Ice/interceptor", ["core"]),
     ("Ice/stringConverter", ["core"]),
-    ("Ice/udp", ["core"]),
+    ("Ice/udp", ["core", "nofreebsdjail"]),
     ("Ice/defaultServant", ["core"]),
     ("Ice/defaultValue", ["core"]),
     ("Ice/invoke", ["core", "novc6"]),
@@ -85,7 +85,7 @@
     ("IceStorm/federation2", ["service", "novc90", "nomingw"]),
     ("IceStorm/stress", ["service", "stress", "novc90", "noappverifier", "nomingw"]), # Too slow with appverifier.
     ("IceStorm/rep1", ["service", "novc90", "nomingw"]),
-    ("IceStorm/repgrid", ["service", "novc90", "nomingw"]),
+    ("IceStorm/repgrid", ["service", "novc90", "nomingw", "nofreebsd"]),
     ("IceStorm/repstress", ["service", "noipv6", "stress", "novc90", "nomingw"]),
     ("FreezeScript/dbmap", ["once", "novc90", "nomingw"]),
     ("FreezeScript/evictor", ["once", "novc90", "nomingw"]),
@@ -106,8 +107,8 @@
 #
 if TestUtil.isWin32() or os.getuid() == 0:
     tests += [
-        ("IceUtil/priority", ["core", "nodarwin"]),
-        ("Ice/threadPoolPriority", ["core", "nodarwin", "nomx"])
+        ("IceUtil/priority", ["core", "nodarwin", "nofreebsd"]),
+        ("Ice/threadPoolPriority", ["core", "nodarwin", "nofreebsd", "nomx"])
         ]
 
 if __name__ == "__main__":
