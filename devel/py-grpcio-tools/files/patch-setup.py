--- setup.py.orig	2022-10-01 13:52:51 UTC
+++ setup.py
@@ -149,7 +149,7 @@ if EXTRA_ENV_COMPILE_ARGS is None:
             # We need to statically link the C++ Runtime, only the C runtime is
             # available dynamically
             EXTRA_ENV_COMPILE_ARGS += ' /MT'
-    elif "linux" in sys.platform or "darwin" in sys.platform:
+    elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_COMPILE_ARGS += ' -fno-wrapv -frtti'
 if EXTRA_ENV_LINK_ARGS is None:
     EXTRA_ENV_LINK_ARGS = ''
@@ -175,7 +175,7 @@ if EXTRA_ENV_LINK_ARGS is None:
     if "darwin" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -Wl,-exported_symbol,_{}'.format(
             _EXT_INIT_SYMBOL)
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += ' -lpthread'
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += ' -latomic'
@@ -206,7 +206,7 @@ if "win32" in sys.platform:
     DEFINE_MACROS += (('WIN32_LEAN_AND_MEAN', 1),)
     if '64bit' in platform.architecture()[0]:
         DEFINE_MACROS += (('MS_WIN64', 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (('HAVE_PTHREAD', 1),)
 
 # By default, Python3 distutils enforces compatibility of
