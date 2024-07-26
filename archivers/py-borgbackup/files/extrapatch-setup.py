--- setup.py.orig	2024-07-02 22:06:38 UTC
+++ setup.py
@@ -181,7 +181,7 @@ if not on_rtd:
     syncfilerange_ext = Extension(
         "borg.platform.syncfilerange", [platform_syncfilerange_source], extra_compile_args=cflags
     )
-    freebsd_ext = Extension("borg.platform.freebsd", [platform_freebsd_source], extra_compile_args=cflags)
+    freebsd_ext = Extension("borg.platform.freebsd", [platform_freebsd_source, 'src/borg/platform/acl_extended_file_np.c'], extra_compile_args=cflags)
     darwin_ext = Extension("borg.platform.darwin", [platform_darwin_source], extra_compile_args=cflags)
     windows_ext = Extension("borg.platform.windows", [platform_windows_source], extra_compile_args=cflags)
 
