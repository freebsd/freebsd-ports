- workaround for https://github.com/dofuuz/python-soxr/issues/25

--- setup.py.orig	2024-07-25 13:58:38 UTC
+++ setup.py
@@ -122,12 +122,13 @@ if '-arm' in platform:
 
 platform = sysconfig.get_platform()
 if '-arm' in platform:
-    compile_args.append('-mfpu=neon')
+    #compile_args.append('-mfpu=neon')
+    pass
 elif '-i686' in platform:
     compile_args.append('-msse')
 
 if get_default_compiler() in ['unix', 'mingw32']:
-    compile_args += ['-std=gnu99', '-Werror=implicit']
+    compile_args += ['-std=gnu99']
 
 extensions = [
     CySoxrExtension(
