--- src/libstd/os/raw/mod.rs.orig	2018-06-19 04:35:53 UTC
+++ src/libstd/os/raw/mod.rs
@@ -29,6 +29,7 @@ use fmt;
           all(target_os = "android", any(target_arch = "aarch64",
                                          target_arch = "arm")),
           all(target_os = "l4re", target_arch = "x86_64"),
+          all(target_os = "freebsd", target_arch = "aarch64"),
           all(target_os = "openbsd", target_arch = "aarch64"),
           all(target_os = "fuchsia", target_arch = "aarch64")))]
 #[stable(feature = "raw_os", since = "1.1.0")] pub type c_char = u8;
@@ -41,6 +42,7 @@ use fmt;
               all(target_os = "android", any(target_arch = "aarch64",
                                              target_arch = "arm")),
               all(target_os = "l4re", target_arch = "x86_64"),
+              all(target_os = "freebsd", target_arch = "aarch64"),
               all(target_os = "openbsd", target_arch = "aarch64"),
               all(target_os = "fuchsia", target_arch = "aarch64"))))]
 #[stable(feature = "raw_os", since = "1.1.0")] pub type c_char = i8;
