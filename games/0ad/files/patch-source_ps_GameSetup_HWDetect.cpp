--- source/ps/GameSetup/HWDetect.cpp.orig	2021-02-28 23:45:13 UTC
+++ source/ps/GameSetup/HWDetect.cpp
@@ -124,6 +124,7 @@ void RunHardwareDetection()
 	scriptInterface.SetProperty(settings, "arch_arm", ARCH_ARM);
 	scriptInterface.SetProperty(settings, "arch_aarch64", ARCH_AARCH64);
 	scriptInterface.SetProperty(settings, "arch_e2k", ARCH_E2K);
+	scriptInterface.SetProperty(settings, "arch_ppc64", ARCH_PPC64);
 
 #ifdef NDEBUG
 	scriptInterface.SetProperty(settings, "build_debug", 0);
