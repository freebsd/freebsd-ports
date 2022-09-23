--- setup.py.orig	2022-08-09 05:49:06 UTC
+++ setup.py
@@ -120,7 +120,7 @@ elif sys.platform.startswith('darwin'):
         '-Wno-sign-compare',
         '-Wno-logical-op-parentheses'
     ])
-elif sys.platform.startswith('linux'):
+elif sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
     sb_include_dirs.append('deps/sphinxbase/include/android')
     extra_compile_args.extend([
         '-Wno-unused-label',
@@ -245,7 +245,7 @@ elif sys.platform.startswith('darwin'):
             extra_link_args=extra_link_args
         )
     )
-elif sys.platform.startswith('linux'):
+elif sys.platform.startswith('linux') or sys.platform.startswith('freebsd'):
     ext_modules.extend([
         Extension(
             name='sphinxbase._ad_pulse',
