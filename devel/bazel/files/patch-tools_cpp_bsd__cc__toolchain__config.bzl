- fix build with recent clang

--- tools/cpp/bsd_cc_toolchain_config.bzl.orig	2025-04-03 02:45:24 UTC
+++ tools/cpp/bsd_cc_toolchain_config.bzl
@@ -108,6 +108,7 @@ def _impl(ctx):
                         flags = [
                             "-no-canonical-prefixes",
                             "-Wno-builtin-macro-redefined",
+                            "-Wno-gnu-offsetof-extensions",
                             "-D__DATE__=\"redacted\"",
                             "-D__TIMESTAMP__=\"redacted\"",
                             "-D__TIME__=\"redacted\"",
