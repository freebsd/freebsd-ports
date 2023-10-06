--- third_party/boringssl/src/crypto/fipsmodule/rand/asm/rdrand-x86_64.pl.orig	2023-08-10 01:51:10 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/rand/asm/rdrand-x86_64.pl
@@ -46,6 +46,7 @@ print<<___;
 .align	16
 CRYPTO_rdrand:
 .cfi_startproc
+	_CET_ENDBR
 	xorq %rax, %rax
 	rdrand $tmp1
 	# An add-with-carry of zero effectively sets %rax to the carry flag.
@@ -64,6 +65,7 @@ CRYPTO_rdrand:
 .align 16
 CRYPTO_rdrand_multiple8_buf:
 .cfi_startproc
+	_CET_ENDBR
 	test $len, $len
 	jz .Lout
 	movq \$8, $tmp1
