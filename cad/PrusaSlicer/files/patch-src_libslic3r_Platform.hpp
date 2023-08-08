--- src/libslic3r/Platform.hpp.orig	2022-09-06 07:09:19 UTC
+++ src/libslic3r/Platform.hpp
@@ -25,6 +25,7 @@ enum class PlatformFlavor
     WSL,             // Microsoft's Windows on Linux (Linux kernel simulated on NTFS kernel)
     WSL2,            // Microsoft's Windows on Linux, version 2 (virtual machine)
     OpenBSD,         // For Platform::BSDUnix
+    FreeBSD,         // For Platform::BSDUnix
     GenericOSX,      // For Platform::OSX
     OSXOnX86,        // For Apple's on Intel X86 CPU
     OSXOnArm,        // For Apple's on Arm CPU
