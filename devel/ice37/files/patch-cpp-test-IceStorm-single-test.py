--- cpp/test/IceStorm/single/test.py.orig	2018-08-27 01:10:47 UTC
+++ cpp/test/IceStorm/single/test.py
@@ -15,12 +15,12 @@
 # send buffer size (causing the received messages to be truncated). See
 # bug #6070 and #7558.
 #
-props = { "Ice.UDP.SndSize" : 2048 * 1024, "Ice.Warn.Dispatch" : 0 }
+props = { "Ice.UDP.SndSize" : 512 * 1024, "Ice.Warn.Dispatch" : 0 }
 persistent = IceStorm(props = props)
 transient = IceStorm(props = props, transient=True)
 replicated = [ IceStorm(replica=i, nreplicas=3, props = props) for i in range(0,3) ]
 
-sub = Subscriber(args=["{testcase.parent.name}"], props = { "Ice.UDP.RcvSize" : 4096 * 1024 }, readyCount=3)
+sub = Subscriber(args=["{testcase.parent.name}"], props = { "Ice.UDP.RcvSize" : 1024 * 1024 }, readyCount=3)
 pub = Publisher(args=["{testcase.parent.name}"])
 
 class IceStormSingleTestCase(IceStormTestCase):
