--- pnio_dcp/pnio_dcp.py.orig	2024-02-18 23:53:00 UTC
+++ pnio_dcp/pnio_dcp.py
@@ -49,7 +49,7 @@ class DCP:
     available through this instance.
     """
 
-    def __init__(self, ip):
+    def __init__(self, ip, timeout=7):
         """
         Create a new instance, use the given ip to select the network interface.
         :param ip: The ip address used to select the network interface.
@@ -57,8 +57,8 @@ class DCP:
         """
         self.src_mac, network_interface = self.__get_network_interface_and_mac_address(ip)
 
-        self.default_timeout = 7  # default timeout for requests (in seconds)
-        self.identify_all_timeout = 7  # timeout to receive all responses for identify_all
+        self.default_timeout = timeout  # default timeout for requests (in seconds)
+        self.identify_all_timeout = timeout  # timeout to receive all responses for identify_all
 
         # the XID is the id of the current transaction and can be used to identify the responses to a request
         self.__xid = int(random.getrandbits(32))  # initialize it with a random value
