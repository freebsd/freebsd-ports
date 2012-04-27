--- pithos/pandora/pandora.py.orig	2011-12-14 16:33:47.000000000 -0800
+++ pithos/pandora/pandora.py	2012-04-27 13:41:25.000000000 -0700
@@ -22,7 +22,7 @@
 from pithos.pandora.xmlrpc import *
 from pithos.pandora.blowfish import Blowfish
 
-PROTOCOL_VERSION = "33"
+PROTOCOL_VERSION = "34"
 RPC_URL = "www.pandora.com/radio/xmlrpc/v"+PROTOCOL_VERSION+"?"
 USER_AGENT = "Mozilla/5.0 (X11; U; Linux i586; de; rv:5.0) Gecko/20100101 Firefox/5.0 (compatible; Pithos/0.3)"
 HTTP_TIMEOUT = 30
@@ -161,12 +161,16 @@
     def connect(self, user, password):
         self.rid = "%07iP"%(int(time.time()) % 10000000)
         self.listenerId = self.authToken = None
+
+        logging.info("Attempting to connect...");
+        timeurl = urllib2.urlopen("http://ridetheclown.com/s2/synctime.php");
+        pandora_time=int(timeurl.read(),10);
+        logging.info("Synctime is %s", pandora_time)
         
-        pandora_time = self.xmlrpc_call('misc.sync', [], [], secure=True, includeTime=False)
-        pandora_time = int(re.sub(r"\D", "", pandora_decrypt(pandora_time)))
         self.time_offset =  pandora_time - time.time()
             
-        user = self.xmlrpc_call('listener.authenticateListener', [user, password], [], secure=True)
+        user = self.xmlrpc_call('listener.authenticateListener', ["",user, password,"html5tuner","","","HTML5",True], [], secure=True)
+
         
         self.webAuthToken = user['webAuthToken']
         self.listenerId = user['listenerId']