--- tools/cpp/bsd_cc_toolchain_config.bzl-	2025-01-24 22:37:03.813550000 +0000
+++ tools/cpp/bsd_cc_toolchain_config.bzl	2025-01-24 22:37:35.606076000 +0000
@@ -108,6 +108,8 @@
                         flags = [
                             "-no-canonical-prefixes",
                             "-Wno-builtin-macro-redefined",
+                            "-Wno-gnu-offsetof-extensions",
+                            "-Wno-c23-extensions",
                             "-D__DATE__=\"redacted\"",
                             "-D__TIMESTAMP__=\"redacted\"",
                             "-D__TIME__=\"redacted\"",
