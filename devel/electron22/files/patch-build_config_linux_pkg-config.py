--- build/config/linux/pkg-config.py.orig	2022-02-07 13:39:41 UTC
+++ build/config/linux/pkg-config.py
@@ -109,7 +109,7 @@ def main():
   # If this is run on non-Linux platforms, just return nothing and indicate
   # success. This allows us to "kind of emulate" a Linux build from other
   # platforms.
-  if "linux" not in sys.platform:
+  if not sys.platform.startswith(tuple(['linux', 'openbsd', 'freebsd'])):
     print("[[],[],[],[],[]]")
     return 0
 
