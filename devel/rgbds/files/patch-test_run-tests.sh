Do not run extra tests that require build

--- test/run-tests.sh.orig	2024-12-31 01:19:31 UTC
+++ test/run-tests.sh
@@ -74,6 +74,6 @@ fi
 	test_downstream pret  pokered          compare pokered.gbc     ea9bcae617fdf159b045185467ae58b2e4a48b9a
 	test_downstream zladx LADX-Disassembly default azle.gbc        d90ac17e9bf17b6c61624ad9f05447bdb5efc01a
 fi
-test_downstream AntonioND ucity   all      ucity.gbc 67e67a4eaefb12ddc98d3caa8959102b885c0405
-test_downstream pinobatch libbet  all      libbet.gb 7001af0f0664ba4e941310cde2c4c8392423abd2
-test_downstream LIJI32    SameBoy bootroms build/bin/BootROMs/cgb_boot.bin 113903775a9d34b798c2f8076672da6626815a91
+#test_downstream AntonioND ucity   all      ucity.gbc 67e67a4eaefb12ddc98d3caa8959102b885c0405
+#test_downstream pinobatch libbet  all      libbet.gb 7001af0f0664ba4e941310cde2c4c8392423abd2
+#test_downstream LIJI32    SameBoy bootroms build/bin/BootROMs/cgb_boot.bin 113903775a9d34b798c2f8076672da6626815a91
