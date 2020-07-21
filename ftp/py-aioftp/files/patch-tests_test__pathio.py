--- tests/test_pathio.py.orig	2020-07-09 13:12:10 UTC
+++ tests/test_pathio.py
@@ -252,7 +252,7 @@ async def test_unlink_not_exist(path_io, temp_dir):
 
 @pytest.mark.asyncio
 async def test_unlink_on_dir(path_io, temp_dir):
-    with universal_exception_reason(IsADirectoryError):
+    with universal_exception_reason(IsADirectoryError, PermissionError):
         await path_io.unlink(temp_dir)
 
 
