--- third_party/boringssl/src/crypto/chacha/asm/chacha-x86_64.pl.orig	2023-02-01 18:45:16 UTC
+++ third_party/boringssl/src/crypto/chacha/asm/chacha-x86_64.pl
@@ -78,6 +78,7 @@ $code.=<<___;
 
 .extern OPENSSL_ia32cap_P
 
+.rodata
 .align	64
 .Lzero:
 .long	0,0,0,0
@@ -107,6 +108,7 @@ $code.=<<___;
 .Lsixteen:
 .long	16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16
 .asciz	"ChaCha20 for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
+.previous
 ___
 
 sub AUTOLOAD()          # thunk [simplified] 32-bit style perlasm
