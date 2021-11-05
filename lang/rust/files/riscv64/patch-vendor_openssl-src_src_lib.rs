--- vendor/openssl-src/src/lib.rs.orig	2021-11-04 11:27:54 UTC
+++ vendor/openssl-src/src/lib.rs
@@ -260,6 +260,7 @@ impl Build {
             "powerpc64le-unknown-freebsd" => "BSD-generic64",
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "powerpc64le-unknown-linux-musl" => "linux-ppc64le",
+            "riscv64gc-unknown-freebsd" => "BSD-generic64",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
