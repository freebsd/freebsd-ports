--- src/libstd/os/raw/mod.rs.orig	2018-10-24 20:00:01 UTC
+++ src/libstd/os/raw/mod.rs
@@ -27,6 +27,7 @@
           all(target_os = "android", any(target_arch = "aarch64",
                                          target_arch = "arm")),
           all(target_os = "l4re", target_arch = "x86_64"),
+          all(target_os = "freebsd", target_arch = "aarch64"),
           all(target_os = "netbsd", any(target_arch = "aarch64",
                                         target_arch = "arm",
                                         target_arch = "powerpc")),
@@ -42,6 +43,7 @@
               all(target_os = "android", any(target_arch = "aarch64",
                                              target_arch = "arm")),
               all(target_os = "l4re", target_arch = "x86_64"),
+              all(target_os = "freebsd", target_arch = "aarch64"),
               all(target_os = "netbsd", any(target_arch = "aarch64",
                                             target_arch = "arm",
                                             target_arch = "powerpc")),
