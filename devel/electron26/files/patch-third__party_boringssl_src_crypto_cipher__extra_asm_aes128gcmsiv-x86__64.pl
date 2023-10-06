--- third_party/boringssl/src/crypto/cipher_extra/asm/aes128gcmsiv-x86_64.pl.orig	2023-08-10 01:51:10 UTC
+++ third_party/boringssl/src/crypto/cipher_extra/asm/aes128gcmsiv-x86_64.pl
@@ -134,6 +134,7 @@ $code.=<<___;
 .align 16
 aesgcmsiv_htable_init:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqa ($H), $T
     vmovdqa $T, $TMP0
     vmovdqa $T, ($Htbl)      # H
@@ -174,6 +175,7 @@ sub aesgcmsiv_htable6_init {
 .align 16
 aesgcmsiv_htable6_init:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqa ($H), $T
     vmovdqa $T, $TMP0
     vmovdqa $T, ($Htbl)      # H
@@ -235,6 +237,7 @@ ___
 .align 16
 aesgcmsiv_htable_polyval:
 .cfi_startproc
+    _CET_ENDBR
     test  $len, $len
     jnz   .Lhtable_polyval_start
     ret
@@ -420,6 +423,7 @@ sub aesgcmsiv_polyval_horner {
 .align 16
 aesgcmsiv_polyval_horner:
 .cfi_startproc
+    _CET_ENDBR
     test $L, $L
     jnz .Lpolyval_horner_start
     ret
@@ -460,6 +464,7 @@ $code.=<<___;
 .align 16
 aes128gcmsiv_aes_ks:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqu (%rdi), %xmm1           # xmm1 = user key
     vmovdqa %xmm1, (%rsi)           # rsi points to output
 
@@ -521,6 +526,7 @@ $code.=<<___;
 .align 16
 aes256gcmsiv_aes_ks:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqu (%rdi), %xmm1
     vmovdqu 16(%rdi), %xmm3
     vmovdqa %xmm1, (%rsi)
@@ -614,6 +620,7 @@ ___
 .align 16
 aes128gcmsiv_aes_ks_enc_x1:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqa (%rcx), %xmm1                 # xmm1 = first 16 bytes of random key
     vmovdqa 0*16(%rdi), $BLOCK1
 
@@ -687,6 +694,7 @@ ___
 .align 16
 aes128gcmsiv_kdf:
 .cfi_startproc
+    _CET_ENDBR
 # parameter 1: %rdi                         Pointer to NONCE
 # parameter 2: %rsi                         Pointer to CT
 # parameter 4: %rdx                         Pointer to keys
@@ -787,6 +795,7 @@ ___
 .align 16
 aes128gcmsiv_enc_msg_x4:
 .cfi_startproc
+    _CET_ENDBR
     test $LEN, $LEN
     jnz .L128_enc_msg_x4_start
     ret
@@ -984,6 +993,7 @@ ___
 .align 16
 aes128gcmsiv_enc_msg_x8:
 .cfi_startproc
+    _CET_ENDBR
     test $LEN, $LEN
     jnz .L128_enc_msg_x8_start
     ret
@@ -1239,6 +1249,7 @@ ___
 
   $code.=<<___;
 .cfi_startproc
+    _CET_ENDBR
     test \$~15, $LEN
     jnz .L${labelPrefix}_dec_start
     ret
@@ -1578,6 +1589,7 @@ sub aes128gcmsiv_ecb_enc_block {
 .align 16
 aes128gcmsiv_ecb_enc_block:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqa (%rdi), $STATE_1
 
     vpxor       ($KSp), $STATE_1, $STATE_1
@@ -1670,6 +1682,7 @@ ___
 .align 16
 aes256gcmsiv_aes_ks_enc_x1:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqa con1(%rip), $CON_MASK    # CON_MASK  = 1,1,1,1
     vmovdqa mask(%rip), $MASK_256    # MASK_256
     vmovdqa ($PT), $BLOCK1
@@ -1711,6 +1724,7 @@ sub aes256gcmsiv_ecb_enc_block {
 .align 16
 aes256gcmsiv_ecb_enc_block:
 .cfi_startproc
+    _CET_ENDBR
     vmovdqa (%rdi), $STATE_1
     vpxor ($KSp), $STATE_1, $STATE_1
     vaesenc 1*16($KSp), $STATE_1, $STATE_1
@@ -1794,6 +1808,7 @@ ___
 .align 16
 aes256gcmsiv_enc_msg_x4:
 .cfi_startproc
+    _CET_ENDBR
     test $LEN, $LEN
     jnz .L256_enc_msg_x4_start
     ret
@@ -1994,6 +2009,7 @@ ___
 .align 16
 aes256gcmsiv_enc_msg_x8:
 .cfi_startproc
+    _CET_ENDBR
     test $LEN, $LEN
     jnz .L256_enc_msg_x8_start
     ret
@@ -2200,6 +2216,7 @@ ___
 .align 16
 aes256gcmsiv_kdf:
 .cfi_startproc
+    _CET_ENDBR
 # parameter 1: %rdi                         Pointer to NONCE
 # parameter 2: %rsi                         Pointer to CT
 # parameter 4: %rdx                         Pointer to keys
