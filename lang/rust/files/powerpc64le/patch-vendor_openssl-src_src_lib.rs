--- vendor/openssl-src/src/lib.rs.orig	2020-09-30 18:01:13.855023000 -0500
+++ vendor/openssl-src/src/lib.rs	2020-09-30 18:02:06.365292000 -0500
@@ -173,6 +173,7 @@ impl Build {
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
+            "powerpc64le-unknown-freebsd" => "BSD-generic64",
             "powerpc64le-unknown-linux-gnu" => "linux-ppc64le",
             "riscv64gc-unknown-linux-gnu" => "linux-generic64",
             "s390x-unknown-linux-gnu" => "linux64-s390x",
