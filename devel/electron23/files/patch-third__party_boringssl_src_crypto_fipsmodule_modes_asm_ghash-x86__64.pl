--- third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-x86_64.pl.orig	2023-02-01 18:45:16 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/modes/asm/ghash-x86_64.pl
@@ -1275,6 +1275,7 @@ ___
 }
 
 $code.=<<___;
+.rodata
 .align	64
 .Lbswap_mask:
 	.byte	15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
@@ -1286,6 +1287,7 @@ $code.=<<___;
 
 .asciz	"GHASH for x86_64, CRYPTOGAMS by <appro\@openssl.org>"
 .align	64
+.previous
 ___
 
 if ($win64) {
