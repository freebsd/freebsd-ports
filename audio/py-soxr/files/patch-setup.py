- workaround for https://github.com/dofuuz/python-soxr/issues/25

--- setup.py.orig	2024-01-24 02:08:37 UTC
+++ setup.py
@@ -122,7 +122,8 @@ if '-arm' in platform:
 
 platform = sysconfig.get_platform()
 if '-arm' in platform:
-    compile_args.append('-mfpu=neon')
+    #compile_args.append('-mfpu=neon')
+    pass
 elif '-i686' in platform:
     compile_args.append('-msse')
 
