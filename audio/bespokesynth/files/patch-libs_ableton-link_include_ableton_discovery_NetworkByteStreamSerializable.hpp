--- libs/ableton-link/include/ableton/discovery/NetworkByteStreamSerializable.hpp.orig	2023-11-14 04:48:57 UTC
+++ libs/ableton-link/include/ableton/discovery/NetworkByteStreamSerializable.hpp
@@ -22,7 +22,7 @@
 #include <ableton/platforms/asio/AsioWrapper.hpp>
 #if defined(LINK_PLATFORM_MACOSX)
 #include <ableton/platforms/darwin/Darwin.hpp>
-#elif defined(LINK_PLATFORM_LINUX)
+#elif defined(LINK_PLATFORM_LINUX) || defined(__FreeBSD__)
 #include <ableton/platforms/linux/Linux.hpp>
 #elif defined(LINK_PLATFORM_WINDOWS)
 #include <ableton/platforms/windows/Windows.hpp>
