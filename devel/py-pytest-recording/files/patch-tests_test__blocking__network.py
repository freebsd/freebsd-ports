--- tests/test_blocking_network.py.orig	2020-02-02 00:00:00 UTC
+++ tests/test_blocking_network.py
@@ -10,11 +10,9 @@ from pytest_recording.network import blocking_context
 
 from pytest_recording.network import blocking_context
 
-# Windows doesn’t have AF_NETLINK & AF_UNIX
 try:
-    from socket import AF_NETLINK, AF_UNIX
+    from socket import AF_UNIX
 except ImportError:
-    AF_NETLINK = None  # type: ignore[assignment]
     AF_UNIX = None  # type: ignore[assignment]
 
 
@@ -28,7 +26,6 @@ except ImportError as exc:
     pycurl = None  # type: ignore[assignment]
 
 
-skip_netlink = pytest.mark.skipif(AF_NETLINK is None, reason="AF_NETLINK not available on this platform")
 skip_unix = pytest.mark.skipif(AF_UNIX is None, reason="AF_UNIX not available on this platform")
 
 
@@ -174,13 +171,6 @@ def test_block_network_blocked_socket():
         call("./blocked_socket", AF_UNIX, SOCK_STREAM)
 
 
-# When not AF_UNIX, AF_INET or AF_INET6 socket is used
-# Then socket.socket.connect call is blocked, even if resource name is in the allowed list
-@skip_netlink
-@pytest.mark.block_network(allowed_hosts=["./allowed_socket", "127.0.0.1", "0"])
-def test_blocked():
-    with pytest.raises(RuntimeError, match=r"^Network is disabled$"):
-        call((0, 0), AF_NETLINK, SOCK_RAW)
 
 
 # When record is disabled
