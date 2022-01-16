--- python/test/Ice/info/AllTests.py.orig	2022-01-15 23:22:20 UTC
+++ python/test/Ice/info/AllTests.py
@@ -2,12 +2,31 @@
 # Copyright (c) ZeroC, Inc. All rights reserved.
 #
 
-import Ice, Test, sys, threading
+import Ice, Test, sys, subprocess, threading
 
 def test(b):
     if not b:
         raise RuntimeError('test assertion failed')
 
+def isFreeBSD():
+    return sys.platform.startswith("freebsd")
+
+def sysctl(key):
+    p = subprocess.Popen("sysctl -n "+key, shell=1, stdout=subprocess.PIPE)
+    try:
+        result = p.communicate()[0].strip()
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
 def getTCPEndpointInfo(info):
     while(info):
         if isinstance(info, Ice.TCPEndpointInfo):
@@ -114,7 +133,7 @@ def allTests(helper, communicator):
         test(tcpEndpoint.port == 15000)
 
     tcpEndpoint = getTCPEndpointInfo(publishedEndpoints[0].getInfo())
-    test(tcpEndpoint.host == "127.0.0.1")
+    test(tcpEndpoint.host == "127.0.0.1" or isFreeBSDJail())
     test(tcpEndpoint.port == 15000)
 
     adapter.destroy()
@@ -134,7 +153,7 @@ def allTests(helper, communicator):
     tcpinfo = getTCPEndpointInfo(base.ice_getConnection().getEndpoint().getInfo())
     test(tcpinfo.port == port)
     test(not tcpinfo.compress)
-    test(tcpinfo.host == defaultHost)
+    test(tcpinfo.host == defaultHost or isFreeBSDJail())
 
     ctx = testIntf.getEndpointInfoAsContext()
     test(ctx["host"] == tcpinfo.host)
@@ -144,7 +163,7 @@ def allTests(helper, communicator):
 
     udp = base.ice_datagram().ice_getConnection().getEndpoint().getInfo()
     test(udp.port == port)
-    test(udp.host == defaultHost)
+    test(udp.host == defaultHost or isFreeBSDJail())
 
     print("ok")
 
@@ -160,8 +179,8 @@ def allTests(helper, communicator):
     test(len(info.adapterName) == 0)
     test(tcpinfo.remotePort == port)
     if defaultHost == '127.0.0.1':
-        test(tcpinfo.remoteAddress == defaultHost)
-        test(tcpinfo.localAddress == defaultHost)
+        test(tcpinfo.remoteAddress == defaultHost or isFreeBSDJail())
+        test(tcpinfo.localAddress == defaultHost or isFreeBSDJail())
     test(tcpinfo.rcvSize >= 1024)
     test(tcpinfo.sndSize >= 2048)
 
