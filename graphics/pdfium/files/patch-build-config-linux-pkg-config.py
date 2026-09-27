--- build/config/linux/pkg-config.py.orig	2025-01-01 00:00:00 UTC
+++ build/config/linux/pkg-config.py
@@ -145,7 +145,7 @@
     # If this is run on non-Linux platforms, just return nothing and indicate
     # success. This allows us to "kind of emulate" a Linux build from other
     # platforms.
-    if "linux" not in sys.platform:
+    if "linux" not in sys.platform and "freebsd" not in sys.platform:
         if options.dridriverdir or options.libdir:
             sys.stdout.write("")
             return 0
