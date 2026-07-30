-- Replace aiomisc.timeout with pytest.mark.timeout
-- Tests require aiomisc-pytest which is not available as a FreeBSD port
-- This patch removes the aiomisc dependency and uses pytest.mark.timeout instead

--- tests/test_asyncio_adapter.py.orig	2026-02-24 06:48:06 UTC
+++ tests/test_asyncio_adapter.py
@@ -3,11 +3,10 @@
 import os
 from unittest.mock import Mock
 
-import aiomisc
 import pytest
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_adapter(tmp_path, async_context_maker):
     async with async_context_maker() as context:
         with open(str(tmp_path / "temp.bin"), "wb+") as fp:
@@ -38,7 +37,7 @@
             assert hashlib.md5(bytes(data)).hexdigest() == expected_hash
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_bad_file_descritor(tmp_path, async_context_maker):
     async with async_context_maker() as context:
         with open(str(tmp_path / "temp.bin"), "wb+") as fp:
@@ -63,7 +62,7 @@
     event_loop.set_exception_handler(current_handler)
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_operations_cancel_cleanly(
     tmp_path, async_context_maker, asyncio_exception_handler
 ):
