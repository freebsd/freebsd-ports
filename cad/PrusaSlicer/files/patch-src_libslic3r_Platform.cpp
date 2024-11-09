--- src/libslic3r/Platform.cpp.orig	2024-09-18 13:39:04 UTC
+++ src/libslic3r/Platform.cpp
@@ -90,6 +90,10 @@ void detect_platform()
     BOOST_LOG_TRIVIAL(info) << "Platform: OpenBSD";
 	s_platform 		  = Platform::BSDUnix;
 	s_platform_flavor = PlatformFlavor::OpenBSD;
+#elif defined(__FreeBSD__)
+    BOOST_LOG_TRIVIAL(info) << "Platform: FreeBSD";
+	s_platform 		  = Platform::BSDUnix;
+	s_platform_flavor = PlatformFlavor::FreeBSD;
 #else
 	// This should not happen.
     BOOST_LOG_TRIVIAL(info) << "Platform: Unknown";
@@ -138,6 +142,7 @@ std::string platform_flavor_to_string(PlatformFlavor p
         case PlatformFlavor::WSL             : return "WSL";
         case PlatformFlavor::WSL2            : return "WSL2";
         case PlatformFlavor::OpenBSD         : return "OpenBSD";
+        case PlatformFlavor::FreeBSD         : return "FreeBSD";
         case PlatformFlavor::GenericOSX      : return "GenericOSX";
         case PlatformFlavor::OSXOnX86        : return "OSXOnX86";
         case PlatformFlavor::OSXOnArm        : return "OSXOnArm";
