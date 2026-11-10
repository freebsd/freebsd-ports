-- Treat FreeBSD as a Linux-like target for pkg-config so system library
-- .pc files are queried instead of returning empty results.
--- build/config/linux/pkg-config.py.orig	1970-01-01 00:00:00 UTC
+++ build/config/linux/pkg-config.py
@@ -143,7 +143,7 @@ def main():
     )
     (options, args) = parser.parse_args()
 
-    if "linux" not in sys.platform:
+    if "linux" not in sys.platform and "freebsd" not in sys.platform:
         if (
             sys.platform == 'darwin'
             and options.sysroot
