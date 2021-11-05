--- src/doc/rustc/src/platform-support.md.orig	2021-11-04 11:32:01 UTC
+++ src/doc/rustc/src/platform-support.md
@@ -261,6 +261,7 @@ target | std | host | notes
 `riscv32gc-unknown-linux-gnu` |   |   | RISC-V Linux (kernel 5.4, glibc 2.33)
 `riscv32gc-unknown-linux-musl` |   |   | RISC-V Linux (kernel 5.4, musl + RISCV32 support patches)
 `riscv32imc-esp-espidf` | ✓ |  | RISC-V ESP-IDF
+`riscv64gc-unknown-freebsd` |   |   | RISC-V FreeBSD
 `riscv64gc-unknown-linux-musl` |   |   | RISC-V Linux (kernel 4.20, musl 1.2.0)
 `s390x-unknown-linux-musl` |  |  | S390x Linux (kernel 2.6.32, MUSL)
 `sparc-unknown-linux-gnu` | ✓ |  | 32-bit SPARC Linux
