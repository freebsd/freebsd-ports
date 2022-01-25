--- modules/core/src/system.cpp.orig	2022-01-25 17:17:25 UTC
+++ modules/core/src/system.cpp
@@ -630,7 +630,7 @@ struct HWFeatures
             }
         }
     #elif (defined __ppc64__ || defined __PPC64__) && defined __FreeBSD__
-        unsigned int hwcap = 0;
+        unsigned long hwcap = 0;
         elf_aux_info(AT_HWCAP, &hwcap, sizeof(hwcap));
         if (hwcap & PPC_FEATURE_HAS_VSX) {
             elf_aux_info(AT_HWCAP2, &hwcap, sizeof(hwcap));
