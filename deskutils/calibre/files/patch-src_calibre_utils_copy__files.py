--- src/calibre/utils/copy_files.py.orig	2023-04-21 02:50:25 UTC
+++ src/calibre/utils/copy_files.py
@@ -127,7 +127,7 @@ class WindowsFileCopier:
             winutil.delete_file(make_long_path_useable(src_path))
 
 
-def get_copier() -> Union[UnixFileCopier | WindowsFileCopier]:
+def get_copier() -> Union[UnixFileCopier, WindowsFileCopier]:
     return WindowsFileCopier() if iswindows else UnixFileCopier()
 
 
