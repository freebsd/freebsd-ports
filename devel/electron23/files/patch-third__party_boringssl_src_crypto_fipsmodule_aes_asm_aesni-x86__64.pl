--- third_party/boringssl/src/crypto/fipsmodule/aes/asm/aesni-x86_64.pl.orig	2023-02-01 18:45:16 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/aes/asm/aesni-x86_64.pl
@@ -4727,6 +4727,7 @@ ___
 }
 
 $code.=<<___;
+.rodata
 .align	64
 .Lbswap_mask:
 	.byte	15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0
@@ -4749,6 +4750,7 @@ $code.=<<___;
 
 .asciz  "AES for Intel AES-NI, CRYPTOGAMS by <appro\@openssl.org>"
 .align	64
+.previous
 ___
 
 # EXCEPTION_DISPOSITION handler (EXCEPTION_RECORD *rec,ULONG64 frame,
