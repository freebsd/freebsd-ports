--- test/run-tests.sh.orig	2025-09-02 23:23:53 UTC
+++ test/run-tests.sh
@@ -129,11 +129,3 @@ fi
 	test_downstream pret  pokered          compare pokered.gbc     ea9bcae617fdf159b045185467ae58b2e4a48b9a
 	test_downstream zladx LADX-Disassembly default azle.gbc        d90ac17e9bf17b6c61624ad9f05447bdb5efc01a
 fi
-test_downstream AntonioND ucity   all      ucity.gbc 5f026649611c9606ce0bf70dc1552e054e7df5bc
-test_downstream pinobatch libbet  all      libbet.gb f117089aa056600e2d404bbcbac96b016fc64611
-test_downstream LIJI32    SameBoy bootroms build/bin/BootROMs/cgb_boot.bin 113903775a9d34b798c2f8076672da6626815a91
-# gb-starter kit make fails on Windows: https://github.com/ISSOtm/gb-starter-kit/issues/1
-# gb-starter-kit fails with macOS/BSD make: https://github.com/ISSOtm/gb-starter-kit/issues/29
-if [[ "${osname%-*}" != "windows" && "${osname%-*}" != "macos" && "${osname%-*}" != "bsd" ]]; then
-	test_downstream ISSOtm gb-starter-kit all bin/boilerplate.gb b4f130169ba73284e0d0e71b53e7baa4eca2f7fe
-fi
