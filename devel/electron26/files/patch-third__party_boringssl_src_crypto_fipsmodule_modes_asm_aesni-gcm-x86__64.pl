--- third_party/boringssl/src/crypto/fipsmodule/modes/asm/aesni-gcm-x86_64.pl.orig	2023-08-10 01:51:10 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/modes/asm/aesni-gcm-x86_64.pl
@@ -442,6 +442,7 @@ $code.=<<___;
 aesni_gcm_decrypt:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 	xor	%rax,%rax
 
 	# We call |_aesni_ctr32_ghash_6x|, which requires at least 96 (0x60)
@@ -715,6 +716,7 @@ _aesni_ctr32_6x:
 aesni_gcm_encrypt:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 #ifdef BORINGSSL_DISPATCH_TEST
 .extern	BORINGSSL_function_hit
 	movb \$1,BORINGSSL_function_hit+2(%rip)
@@ -1089,6 +1091,7 @@ $code=<<___;	# assembler is too old
 .globl	aesni_gcm_encrypt
 .type	aesni_gcm_encrypt,\@abi-omnipotent
 aesni_gcm_encrypt:
+	_CET_ENDBR
 	xor	%eax,%eax
 	ret
 .size	aesni_gcm_encrypt,.-aesni_gcm_encrypt
@@ -1096,6 +1099,7 @@ aesni_gcm_encrypt:
 .globl	aesni_gcm_decrypt
 .type	aesni_gcm_decrypt,\@abi-omnipotent
 aesni_gcm_decrypt:
+	_CET_ENDBR
 	xor	%eax,%eax
 	ret
 .size	aesni_gcm_decrypt,.-aesni_gcm_decrypt
