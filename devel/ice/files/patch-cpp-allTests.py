--- cpp/allTests.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/allTests.py
@@ -68,7 +68,7 @@ tests = [
     ("Ice/servantLocator", ["core"]),
     ("Ice/interceptor", ["core"]),
     ("Ice/stringConverter", ["core"]),
-    ("Ice/udp", ["core"]),
+    ("Ice/udp", ["core", "nofreebsdjail"]),
     ("Ice/defaultServant", ["core"]),
     ("Ice/defaultValue", ["core"]),
     ("Ice/invoke", ["core"]),
@@ -92,11 +92,11 @@ tests = [
     ("IceStorm/federation2", ["service", "novc100", "nomingw"]),
     ("IceStorm/stress", ["service", "stress", "novc100", "nomingw"]), # Too slow with appverifier.
     ("IceStorm/rep1", ["service", "novc100", "nomingw"]),
-    ("IceStorm/repgrid", ["service", "novc100", "nomingw"]),
+    ("IceStorm/repgrid", ["service", "novc100", "nomingw", "nofreebsd"]),
     ("IceStorm/repstress", ["service", "noipv6", "stress", "novc100", "nomingw"]),
     ("FreezeScript/dbmap", ["once", "novc100", "nomingw"]),
     ("FreezeScript/evictor", ["once", "novc100", "nomingw"]),
-    ("IceDiscovery/simple", ["service"]),
+    ("IceDiscovery/simple", ["service", "nofreebsdjail"]),
     ("IceGrid/simple", ["service", "novc100", "nomingw"]),
     ("IceGrid/fileLock", ["service", "novc100", "nomingw"]),
     ("IceGrid/deployer", ["service", "novc100", "nomingw"]),
@@ -125,8 +125,8 @@ tests = [
 #
 if TestUtil.isWin32() or os.getuid() == 0:
     tests += [
-        ("IceUtil/priority", ["core", "nodarwin"]),
-        ("Ice/threadPoolPriority", ["core", "nodarwin", "nomx"])
+        ("IceUtil/priority", ["core", "nodarwin", "nofreebsd"]),
+        ("Ice/threadPoolPriority", ["core", "nodarwin", "nofreebsd", "nomx"])
         ]
 
 if __name__ == "__main__":
