--- third_party/boringssl/src/crypto/fipsmodule/aes/asm/vpaes-x86_64.pl.orig	2023-02-01 18:45:16 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/aes/asm/vpaes-x86_64.pl
@@ -1288,6 +1288,7 @@ _vpaes_preheat:
 ##                                                    ##
 ########################################################
 .type	_vpaes_consts,\@object
+.rodata
 .align	64
 _vpaes_consts:
 .Lk_inv:	# inv, inva
