--- vendor/openssl-src/src/lib.rs.orig	2021-04-23 22:26:56.124321000 -0500
+++ vendor/openssl-src/src/lib.rs	2021-04-23 22:27:38.643235000 -0500
@@ -194,6 +194,7 @@ impl Build {
             "mips64el-unknown-linux-gnuabi64" => "linux64-mips64",
             "mipsel-unknown-linux-gnu" => "linux-mips32",
             "mipsel-unknown-linux-musl" => "linux-mips32",
+            "powerpc-unknown-freebsd" => "BSD-generic32",
             "powerpc-unknown-linux-gnu" => "linux-ppc",
             "powerpc64-unknown-freebsd" => "BSD-generic64",
             "powerpc64-unknown-linux-gnu" => "linux-ppc64",
