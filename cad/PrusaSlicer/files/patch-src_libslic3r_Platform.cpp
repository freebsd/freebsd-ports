--- src/libslic3r/Platform.cpp.orig	2021-04-20 12:16:52 UTC
+++ src/libslic3r/Platform.cpp
@@ -49,6 +49,10 @@ void detect_platform()
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
