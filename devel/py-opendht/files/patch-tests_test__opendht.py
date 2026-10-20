-- Skip test_bootstrap: it pings between two local nodes over the network and
-- fails in the build/test environment.
-- See https://github.com/savoirfairelinux/opendht/issues/683

--- tests/test_opendht.py.orig	2026-10-18 17:23:44 UTC
+++ tests/test_opendht.py
@@ -11,6 +11,7 @@ class OpenDhtTester(unittest.TestCase):
             del r
 
     # test that bootstraping works (raw address)
+    @unittest.skip("network ping fails in the build sandbox")
     def test_bootstrap(self):
         a = dht.DhtRunner()
         a.run()
