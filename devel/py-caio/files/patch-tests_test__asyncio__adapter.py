-- Replace aiomisc.timeout with pytest.mark.timeout
-- Tests require aiomisc-pytest which is not available as a FreeBSD port
-- This patch removes the aiomisc dependency and uses pytest.mark.timeout instead

--- tests/test_asyncio_adapter.py.orig	2026-10-11 17:34:52 UTC
+++ tests/test_asyncio_adapter.py
@@ -3,12 +3,11 @@ from unittest.mock import Mock
 import os
 from unittest.mock import Mock
 
-import aiomisc
 import pytest
 from conftest import import_backend_or_skip
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_linux_uring_asyncio_forwards_context_kwargs():
     uring_asyncio = import_backend_or_skip("caio.linux_uring_asyncio")
 
@@ -25,7 +24,7 @@ async def test_linux_uring_asyncio_forwards_context_kw
         assert context.deferred is True
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_adapter(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -56,7 +55,7 @@ async def test_adapter(tmp_path, async_context):
         assert hashlib.md5(bytes(data)).hexdigest() == expected_hash
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_bad_file_descritor(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -81,7 +80,7 @@ async def asyncio_exception_handler():
     event_loop.set_exception_handler(current_handler)
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_operations_cancel_cleanly(
     tmp_path, async_context, asyncio_exception_handler
 ):
@@ -107,7 +106,7 @@ async def test_operations_cancel_cleanly(
             asyncio_exception_handler.assert_not_called()
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_write_operations_cancel_cleanly(
     tmp_path, async_context, asyncio_exception_handler
 ):
@@ -134,7 +133,7 @@ async def test_write_operations_cancel_cleanly(
             asyncio_exception_handler.assert_not_called()
 
 
-@aiomisc.timeout(3)
+@pytest.mark.timeout(3)
 async def test_cancel_before_first_step_runs(tmp_path, async_context, asyncio_exception_handler):
     """Cancelling right after the op's own first step (submit queued, still
     suspended at `await future`) - covers context.cancel() raising ValueError
@@ -161,7 +160,7 @@ async def test_cancel_before_first_step_runs(tmp_path,
         asyncio_exception_handler.assert_not_called()
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_zero_byte_read_and_write(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -171,7 +170,7 @@ async def test_zero_byte_read_and_write(tmp_path, asyn
         assert await context.read(0, fd, 0) == b""
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_partial_read_at_eof(tmp_path, async_context):
     """Requesting more bytes than the file actually has must return exactly
     what's there, not garbage/padding out to the requested size - this
@@ -190,7 +189,7 @@ async def test_partial_read_at_eof(tmp_path, async_con
         assert len(data) == len(payload)
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_fsync_and_fdsync(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -203,7 +202,7 @@ async def test_fsync_and_fdsync(tmp_path, async_contex
         await context.fdsync(fd)
 
 
-@aiomisc.timeout(15)
+@pytest.mark.timeout(15)
 async def test_large_transfer(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -220,7 +219,7 @@ async def test_large_transfer(tmp_path, async_context)
         assert hashlib.sha256(bytes(data)).hexdigest() == expected_hash
 
 
-@aiomisc.timeout(5)
+@pytest.mark.timeout(5)
 async def test_write_extends_file_sparsely(tmp_path, async_context):
     context = async_context
     with open(str(tmp_path / "temp.bin"), "wb+") as fp:  # noqa: ASYNC230 (brief sync setup, not the operation under test)
@@ -234,7 +233,7 @@ async def test_write_extends_file_sparsely(tmp_path, a
         assert hole == b"\x00" * hole_size
 
 
-@aiomisc.timeout(10)
+@pytest.mark.timeout(10)
 async def test_max_requests_backpressure(tmp_path, async_context_maker):
     """A tiny max_requests must still let far more concurrent operations
     complete correctly - the asyncio-level semaphore is responsible for
@@ -262,7 +261,7 @@ async def test_max_requests_backpressure(tmp_path, asy
             assert results == expected
 
 
-@aiomisc.timeout(10)
+@pytest.mark.timeout(10)
 async def test_concurrent_non_overlapping_chunks(tmp_path, async_context):
     """Writes distinct, non-overlapping regions concurrently, then reads
     them back concurrently - if any backend's buffer handling ever aliased
