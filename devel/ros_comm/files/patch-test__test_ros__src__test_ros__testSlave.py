--- ./test/test_ros/src/test_ros/testSlave.py.orig	2011-03-02 01:15:16.000000000 +0100
+++ ./test/test_ros/src/test_ros/testSlave.py	2011-03-20 15:22:55.000000000 +0100
@@ -69,7 +69,7 @@
         # retrieve handle on node
         self.caller_id = rospy.get_caller_id()
         self.node_api = self.apiSuccess(self.master.lookupNode(self.caller_id, 'test_node'))
-        self.assert_(self.node_api.startswith('http')
+        self.assert_(self.node_api.startswith('http'))
         self.node = xmlrpclib.ServerProxy(self.node_api)
         
     def testGetPid(self):
