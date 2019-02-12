--- python/test/Ice/info/AllTests.py.orig	2018-08-27 01:10:47 UTC
+++ python/test/Ice/info/AllTests.py
@@ -7,12 +7,31 @@
 #
 # **********************************************************************
 
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
@@ -119,7 +138,7 @@ def allTests(communicator):
         test(tcpEndpoint.port == 15000)
 
     tcpEndpoint = getTCPEndpointInfo(publishedEndpoints[0].getInfo())
-    test(tcpEndpoint.host == "127.0.0.1")
+    test(tcpEndpoint.host == "127.0.0.1" or isFreeBSDJail())
     test(tcpEndpoint.port == 15000)
 
     adapter.destroy()
@@ -137,7 +156,7 @@ def allTests(communicator):
     tcpinfo = getTCPEndpointInfo(base.ice_getConnection().getEndpoint().getInfo())
     test(tcpinfo.port == 12010)
     test(not tcpinfo.compress)
-    test(tcpinfo.host == defaultHost)
+    test(tcpinfo.host == defaultHost or isFreeBSDJail())
 
     ctx = testIntf.getEndpointInfoAsContext()
     test(ctx["host"] == tcpinfo.host)
@@ -147,7 +166,7 @@ def allTests(communicator):
 
     udp = base.ice_datagram().ice_getConnection().getEndpoint().getInfo()
     test(udp.port == port)
-    test(udp.host == defaultHost)
+    test(udp.host == defaultHost or isFreeBSDJail())
 
     print("ok")
 
@@ -163,8 +182,8 @@ def allTests(communicator):
     test(len(info.adapterName) == 0)
     test(tcpinfo.remotePort == 12010)
     if defaultHost == '127.0.0.1':
-        test(tcpinfo.remoteAddress == defaultHost)
-        test(tcpinfo.localAddress == defaultHost)
+        test(tcpinfo.remoteAddress == defaultHost or isFreeBSDJail())
+        test(tcpinfo.localAddress == defaultHost or isFreeBSDJail())
     test(tcpinfo.rcvSize >= 1024)
     test(tcpinfo.sndSize >= 2048)
 
