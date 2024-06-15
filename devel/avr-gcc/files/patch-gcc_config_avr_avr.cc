index 510e4cea19f662f30d9474e4b208e3691103934c..74924ab0565779c597d10ee880548640a9dd59ae 100644 (file)
--- gcc/config/avr/avr.cc
+++ gcc/config/avr/avr.cc
@@ -1140,6 +1140,12 @@ avr_option_override (void)
   if (targetm.addr_space.zero_address_valid (ADDR_SPACE_GENERIC))
     flag_delete_null_pointer_checks = 0;
 
+  /* PR ipa/92606: Inter-procedural analysis optimizes data across
+     address-spaces and PROGMEM.  As of v14, the PROGMEM part is
+     still not fixed (and there is still no target hook as proposed
+     in PR92932).  Just disable respective bogus optimization.  */
+  flag_ipa_icf_variables = 0;
+
   if (flag_pic == 1)
     warning (OPT_fpic, "%<-fpic%> is not supported");
   if (flag_pic == 2)
