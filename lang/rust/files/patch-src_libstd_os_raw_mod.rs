--- src/libstd/os/raw/mod.rs.orig	2019-01-16 09:30:27 UTC
+++ src/libstd/os/raw/mod.rs
@@ -27,6 +27,10 @@
           all(target_os = "android", any(target_arch = "aarch64",
                                          target_arch = "arm")),
           all(target_os = "l4re", target_arch = "x86_64"),
+          all(target_os = "freebsd", any(target_arch = "aarch64",
+                                         target_arch = "arm",
+                                         target_arch = "powerpc",
+                                         target_arch = "powerpc64")),
           all(target_os = "netbsd", any(target_arch = "aarch64",
                                         target_arch = "arm",
                                         target_arch = "powerpc")),
@@ -42,6 +46,10 @@
               all(target_os = "android", any(target_arch = "aarch64",
                                              target_arch = "arm")),
               all(target_os = "l4re", target_arch = "x86_64"),
+              all(target_os = "freebsd", any(target_arch = "aarch64",
+                                             target_arch = "arm",
+                                             target_arch = "powerpc",
+                                             target_arch = "powerpc64")),
               all(target_os = "netbsd", any(target_arch = "aarch64",
                                             target_arch = "arm",
                                             target_arch = "powerpc")),
