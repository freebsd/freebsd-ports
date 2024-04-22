--- src/libslic3r/Platform.cpp.orig	2023-12-12 14:21:21 UTC
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
