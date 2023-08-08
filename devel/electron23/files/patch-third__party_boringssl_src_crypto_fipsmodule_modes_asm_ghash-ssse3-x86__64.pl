--- third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-ssse3-x86_64.pl.orig	2023-02-01 18:45:16 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-ssse3-x86_64.pl
@@ -333,6 +333,7 @@ $code .= <<____;
 .cfi_endproc
 .size	gcm_ghash_ssse3,.-gcm_ghash_ssse3
 
+.rodata
 .align	16
 # .Lreverse_bytes is a permutation which, if applied with pshufb, reverses the
 # bytes in an XMM register.
@@ -341,6 +342,7 @@ $code .= <<____;
 # .Llow4_mask is an XMM mask which selects the low four bits of each byte.
 .Llow4_mask:
 .quad	0x0f0f0f0f0f0f0f0f, 0x0f0f0f0f0f0f0f0f
+.previous
 ____
 
 if ($win64) {
