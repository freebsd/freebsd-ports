--- src/libslic3r/Platform.hpp.orig	2024-12-20 11:54:34 UTC
+++ src/libslic3r/Platform.hpp
@@ -29,6 +29,7 @@ enum class PlatformFlavor
     WSL,             // Microsoft's Windows on Linux (Linux kernel simulated on NTFS kernel)
     WSL2,            // Microsoft's Windows on Linux, version 2 (virtual machine)
     OpenBSD,         // For Platform::BSDUnix
+    FreeBSD,         // For Platform::BSDUnix
     GenericOSX,      // For Platform::OSX
     OSXOnX86,        // For Apple's on Intel X86 CPU
     OSXOnArm,        // For Apple's on Arm CPU
