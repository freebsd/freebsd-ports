--- third_party/boringssl/src/crypto/fipsmodule/md5/asm/md5-x86_64.pl.orig	2023-08-10 01:51:10 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/md5/asm/md5-x86_64.pl
@@ -131,6 +131,7 @@ $code .= <<EOF;
 .type md5_block_asm_data_order,\@function,3
 md5_block_asm_data_order:
 .cfi_startproc
+	_CET_ENDBR
 	push	%rbp
 .cfi_push	rbp
 	push	%rbx
