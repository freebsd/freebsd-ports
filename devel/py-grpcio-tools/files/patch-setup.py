--- setup.py.orig	2024-04-26 06:29:22 UTC
+++ setup.py
@@ -178,7 +178,7 @@ if EXTRA_ENV_COMPILE_ARGS is None:
         # Reduce the optimization level from O3 (in many cases) to O1 to
         # workaround gcc misalignment bug with MOVAPS (internal b/329134877)
         EXTRA_ENV_COMPILE_ARGS += " -O1"
-    elif "darwin" in sys.platform:
+    elif "darwin" in sys.platform or "freebsd" in sys.platform:
         # AppleClang by defaults uses C17 so only C++14 needs to be specified.
         EXTRA_ENV_COMPILE_ARGS += " -std=c++14"
         EXTRA_ENV_COMPILE_ARGS += " -fno-wrapv -frtti"
@@ -211,7 +211,7 @@ if EXTRA_ENV_LINK_ARGS is None:
         EXTRA_ENV_LINK_ARGS += " -Wl,-exported_symbol,_{}".format(
             _EXT_INIT_SYMBOL
         )
-    if "linux" in sys.platform or "darwin" in sys.platform:
+    if "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
         EXTRA_ENV_LINK_ARGS += " -lpthread"
         if check_linker_need_libatomic():
             EXTRA_ENV_LINK_ARGS += " -latomic"
@@ -248,7 +248,7 @@ if "win32" in sys.platform:
     )
     if "64bit" in platform.architecture()[0]:
         DEFINE_MACROS += (("MS_WIN64", 1),)
-elif "linux" in sys.platform or "darwin" in sys.platform:
+elif "linux" in sys.platform or "darwin" in sys.platform or "freebsd" in sys.platform:
     DEFINE_MACROS += (("HAVE_PTHREAD", 1),)
 
 
