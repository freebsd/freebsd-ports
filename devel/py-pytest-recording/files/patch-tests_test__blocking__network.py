--- tests/test_blocking_network.py.orig	2025-04-25 08:03:40 UTC
+++ tests/test_blocking_network.py
@@ -1,7 +1,7 @@ from io import BytesIO
 import json
 import sys
 from io import BytesIO
-from socket import AF_INET, AF_NETLINK, AF_UNIX, SOCK_RAW, SOCK_STREAM, socket
+from socket import AF_INET, AF_UNIX, SOCK_RAW, SOCK_STREAM, socket
 
 import pytest
 import requests
@@ -158,14 +158,6 @@ def test_block_network_blocked_socket():
 def test_block_network_blocked_socket():
     with pytest.raises(RuntimeError, match=r"^Network is disabled$"):
         call("./blocked_socket", AF_UNIX, SOCK_STREAM)
-
-
-# When not AF_UNIX, AF_INET or AF_INET6 socket is used
-# Then socket.socket.connect call is blocked, even if resource name is in the allowed list
-@pytest.mark.block_network(allowed_hosts=["./allowed_socket", "127.0.0.1", "0"])
-def test_blocked():
-    with pytest.raises(RuntimeError, match=r"^Network is disabled$"):
-        call((0, 0), AF_NETLINK, SOCK_RAW)
 
 
 # When record is disabled
