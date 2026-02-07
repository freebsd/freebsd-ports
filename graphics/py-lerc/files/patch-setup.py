--- setup.py.orig	2022-07-15 18:25:29 UTC
+++ setup.py
@@ -16,8 +16,8 @@ except Exception:
 
 # Using MANIFEST.in doesn't respect relative paths above the package root.
 # Instead, inspect the location and copy in the binaries if newer.
-BINARY_TYPES = ["*.dll", "*.lib", "*.so*", "*.dylib"]
-PLATFORMS = ["Linux", "MacOS", "windows"]
+BINARY_TYPES = ["*.so*"]
+PLATFORMS = ["FreeBSD"]
 for platform in PLATFORMS:
     platform_dir = join("..", "..", "bin", platform)
     for ext in BINARY_TYPES:
