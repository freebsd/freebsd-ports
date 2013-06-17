--- py/test/Ice/info/AllTests.py.orig	2013-03-11 15:19:47.000000000 +0000
+++ py/test/Ice/info/AllTests.py	2013-05-20 14:25:56.860196743 +0000
@@ -7,12 +7,31 @@
 #
 # **********************************************************************
 
-import Ice, Test, sys, threading
+import Ice, Test, sys, threading, subprocess
 
 def test(b):
     if not b:
         raise RuntimeError('test assertion failed')
 
+def isFreeBSD():
+    return sys.platform.startswith("freebsd")
+
+def sysctl(key):
+    p = subprocess.Popen("sysctl "+key, shell=1, stdout=subprocess.PIPE)
+    try:
+        result = p.communicate()[0].strip().split()[1]
+    except IndexError:
+        return 0    
+    if sys.version_info >= (3,):
+        result = str(result, sys.stdout.encoding)
+    try:
+        return int(result)
+    except ValueError:
+        return result
+
+def isFreeBSDJail():
+    return isFreeBSD() and sysctl("security.jail.jailed")
+
 def allTests(communicator, collocated):
     sys.stdout.write("testing proxy endpoint information... ")
     sys.stdout.flush()
@@ -67,12 +86,12 @@
 
     ipEndpoint = endpoints[0].getInfo()
     test(ipEndpoint.type() == Ice.TCPEndpointType or ipEndpoint.type() == 2)
-    test(ipEndpoint.host == defaultHost)
+    test(ipEndpoint.host == defaultHost or isFreeBSDJail())
     test(ipEndpoint.port > 0)
     test(ipEndpoint.timeout == 15000)
 
     udpEndpoint = endpoints[1].getInfo()
-    test(udpEndpoint.host == defaultHost)
+    test(udpEndpoint.host == defaultHost or isFreeBSDJail())
     test(udpEndpoint.datagram())
     test(udpEndpoint.port > 0)
 
@@ -108,7 +127,7 @@
     ipinfo = base.ice_getConnection().getEndpoint().getInfo()
     test(ipinfo.port == 12010)
     test(not ipinfo.compress)
-    test(ipinfo.host == defaultHost)
+    test(ipinfo.host == defaultHost or isFreeBSDJail())
 
     ctx = testIntf.getEndpointInfoAsContext()
     test(ctx["host"] == ipinfo.host)
@@ -118,7 +137,7 @@
 
     udp = base.ice_datagram().ice_getConnection().getEndpoint().getInfo()
     test(udp.port == 12010)
-    test(udp.host == defaultHost)
+    test(udp.host == defaultHost or isFreeBSDJail())
 
     print("ok")
 
@@ -129,8 +148,8 @@
     test(not info.incoming)
     test(len(info.adapterName) == 0)
     test(info.remotePort == 12010)
-    test(info.remoteAddress == defaultHost)
-    test(info.localAddress == defaultHost)
+    test(info.remoteAddress == defaultHost or isFreeBSDJail())
+    test(info.localAddress == defaultHost or isFreeBSDJail())
 
     ctx = testIntf.getConnectionInfoAsContext()
     test(ctx["incoming"] == "true")
