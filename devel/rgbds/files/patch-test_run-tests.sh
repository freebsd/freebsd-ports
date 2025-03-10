Do not run extra tests that require build

--- test/run-tests.sh.orig	2025-02-02 21:10:40 UTC
+++ test/run-tests.sh
@@ -119,6 +119,6 @@ fi
 	test_downstream pret  pokered          compare pokered.gbc     ea9bcae617fdf159b045185467ae58b2e4a48b9a
 	test_downstream zladx LADX-Disassembly default azle.gbc        d90ac17e9bf17b6c61624ad9f05447bdb5efc01a
 fi
-test_downstream AntonioND ucity   all      ucity.gbc d2f4a7db48ee208b1bd69a78bd492a1c9ac4a030
-test_downstream pinobatch libbet  all      libbet.gb f117089aa056600e2d404bbcbac96b016fc64611
-test_downstream LIJI32    SameBoy bootroms build/bin/BootROMs/cgb_boot.bin 113903775a9d34b798c2f8076672da6626815a91
+#test_downstream AntonioND ucity   all      ucity.gbc d2f4a7db48ee208b1bd69a78bd492a1c9ac4a030
+#test_downstream pinobatch libbet  all      libbet.gb f117089aa056600e2d404bbcbac96b016fc64611
+#test_downstream LIJI32    SameBoy bootroms build/bin/BootROMs/cgb_boot.bin 113903775a9d34b798c2f8076672da6626815a91
