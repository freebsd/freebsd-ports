--- pypy/tool/cpyext/extbuild.py.orig	2017-10-03 10:49:20 UTC
+++ pypy/tool/cpyext/extbuild.py
@@ -244,13 +244,13 @@ def get_sys_info_app(base_dir):
     if sys.platform == 'win32':
         compile_extra = ["/we4013"]
         link_extra = ["/LIBPATH:" + os.path.join(sys.exec_prefix, 'libs')]
-    elif sys.platform == 'darwin':
-        compile_extra = link_extra = None
-        pass
     elif sys.platform.startswith('linux'):
         compile_extra = [
             "-O0", "-g", "-Werror=implicit-function-declaration", "-fPIC"]
         link_extra = None
+    else:
+        compile_extra = link_extra = None
+        pass
     return ExtensionCompiler(
         builddir_base=base_dir,
         include_extra=[get_python_inc()],
