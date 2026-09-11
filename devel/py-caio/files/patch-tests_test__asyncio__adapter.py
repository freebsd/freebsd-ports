-- Replace aiomisc.timeout with pytest.mark.timeout
-- Tests require aiomisc-pytest which is not available as a FreeBSD port
-- This patch removes the aiomisc dependency and uses pytest.mark.timeout instead

--- tests/test_asyncio_adapter.py.orig
+++ tests/test_asyncio_adapter.py
@@ -3,11 +3,10 @@
 import os
 from unittest.mock import Mock
 
-import aiomisc
 import pytest
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_linux_uring_asyncio_forwards_context_kwargs():
     uring_asyncio = pytest.importorskip("caio.linux_uring_asyncio")
 
@@ -24,7 +23,7 @@
         assert context.deferred is True
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_adapter(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -55,7 +54,7 @@
         assert hashlib.md5(bytes(data)).hexdigest() == expected_hash
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_bad_file_descritor(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -80,7 +79,7 @@
     event_loop.set_exception_handler(current_handler)
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_operations_cancel_cleanly(
     tmp_path, async_context, asyncio_exception_handler
 ):
@@ -106,7 +105,7 @@
             asyncio_exception_handler.assert_not_called()
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_write_operations_cancel_cleanly(
     tmp_path, async_context, asyncio_exception_handler
 ):
@@ -133,7 +132,7 @@
             asyncio_exception_handler.assert_not_called()
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_cancel_before_first_step_runs(tmp_path, async_context, asyncio_exception_handler):
     """Cancelling right after the op's own first step (submit queued, still
     suspended at `await future`) - covers context.cancel() raising ValueError
@@ -149,7 +148,7 @@
         asyncio_exception_handler.assert_not_called()
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_zero_byte_read_and_write(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -159,7 +158,7 @@
         assert await context.read(0, fd, 0) == b""
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_partial_read_at_eof(tmp_path, async_context):
     """Requesting more bytes than the file actually has must return exactly
     what's there, not garbage/padding out to the requested size - this
@@ -178,7 +177,7 @@
         assert len(data) == len(payload)
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_fsync_and_fdsync(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -191,7 +190,7 @@
         await context.fdsync(fd)
 
 
-@aiomisc.timeout(15)
+@pytest.mark.timeout(15)
 async def test_large_transfer(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -208,7 +207,7 @@
         assert hashlib.sha256(bytes(data)).hexdigest() == expected_hash
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_write_extends_file_sparsely(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -222,7 +221,7 @@
         assert hole == b"\x00" * hole_size
 
 
-@aiomisc.timeout(10)
+@pytest.mark.timeout(10)
 async def test_max_requests_backpressure(tmp_path, async_context_maker):
     """A tiny max_requests must still let far more concurrent operations
     complete correctly - the asyncio-level semaphore is responsible for
@@ -250,7 +249,7 @@
             assert results == expected
 
 
-@aiomisc.timeout(10)
+@pytest.mark.timeout(10)
 async def test_concurrent_non_overlapping_chunks(tmp_path, async_context):
     """Writes distinct, non-overlapping regions concurrently, then reads
     them back concurrently - if any backend's buffer handling ever aliased
