-- httpx>=0.28 raises httpx.InvalidURL when a literal query string is
-- embedded directly in the path= kwarg of URL.copy_with(); pass it
-- via the separate query= kwarg instead. Upstream pins httpx==0.23.1
-- in its own test extra specifically to avoid this; we use a newer
-- httpx per project convention (upper bounds in pyproject.toml are
-- ignored).

-- Upstreamed: https://github.com/lexiforest/curl_cffi/pull/871

--- tests/unittest/test_async_session.py.orig	2026-09-30 07:13:31 UTC
+++ tests/unittest/test_async_session.py
@@ -219,7 +219,8 @@ async def test_update_params(server):
 async def test_update_params(server):
     async with AsyncSession() as s:
         r = await s.get(
-            str(server.url.copy_with(path="/echo_params?foo=z")), params={"foo": "bar"}
+            str(server.url.copy_with(path="/echo_params", query=b"foo=z")),
+            params={"foo": "bar"},
         )
         assert r.status_code == 200
         assert r.content == b'{"params": {"foo": ["bar"]}}'
