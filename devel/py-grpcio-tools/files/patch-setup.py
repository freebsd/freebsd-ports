--- setup.py.orig	2025-01-22 20:25:32 UTC
+++ setup.py
@@ -190,7 +190,7 @@ if EXTRA_ENV_COMPILE_ARGS is None:
         # Reduce the optimization level from O3 (in many cases) to O1 to
         # workaround gcc misalignment bug with MOVAPS (internal b/329134877)
         EXTRA_ENV_COMPILE_ARGS += " -O1"
-    elif "darwin" in sys.platform:
+    elif "darwin" in sys.platform or "freebsd" in sys.platform:
         # AppleClang by defaults uses C17 so only C++17 needs to be specified.
         EXTRA_ENV_COMPILE_ARGS += " -std=c++17"
         EXTRA_ENV_COMPILE_ARGS += " -fno-wrapv -frtti"
@@ -223,7 +223,7 @@ if EXTRA_ENV_LINK_ARGS is None:
         EXTRA_ENV_LINK_ARGS += " -Wl,-exported_symbol,_{}".format(
             _EXT_INIT_SYMBOL
         )
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += " -lpthread"
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += " -latomic"
@@ -260,7 +260,7 @@ if "win32" in sys.platform:
     )
     if "64bit" in platform.architecture()[0]:
         DEFINE_MACROS += (("MS_WIN64", 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (("HAVE_PTHREAD", 1),)
 
 
