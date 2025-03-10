--- vendor/openssl-src-111.28.2+1.1.1w/src/lib.rs.orig	2021-11-04 11:27:54 UTC
+++ vendor/openssl-src-111.28.2+1.1.1w/src/lib.rs
@@ -284,6 +284,7 @@ impl Build {
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "powerpc64le-unknown-linux-musl" => "linux-ppc64le",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
+            "riscv64gc-unknown-freebsd" => "BSD-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
             "s390x-unknown-linux-musl" => "linux64-s390x",
             "x86_64-apple-darwin" => "darwin64-x86_64-cc",
