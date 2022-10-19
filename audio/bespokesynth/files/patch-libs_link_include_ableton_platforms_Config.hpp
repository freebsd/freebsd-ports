--- libs/link/include/ableton/platforms/Config.hpp.orig	2021-12-03 12:55:21 UTC
+++ libs/link/include/ableton/platforms/Config.hpp
@@ -36,7 +36,7 @@
 #include <ableton/platforms/darwin/ThreadFactory.hpp>
 #include <ableton/platforms/posix/ScanIpIfAddrs.hpp>
 #include <ableton/platforms/stl/Random.hpp>
-#elif defined(LINK_PLATFORM_LINUX)
+#elif defined(LINK_PLATFORM_LINUX) || defined(__FreeBSD__)
 #include <ableton/platforms/asio/Context.hpp>
 #include <ableton/platforms/linux/Clock.hpp>
 #include <ableton/platforms/posix/ScanIpIfAddrs.hpp>
@@ -77,7 +77,7 @@ using IoContext = platforms::asio::Context<platforms::
   platforms::darwin::ThreadFactory>;
 using Random = platforms::stl::Random;
 
-#elif defined(LINK_PLATFORM_LINUX)
+#elif defined(LINK_PLATFORM_LINUX) || defined(__FreeBSD__)
 using Clock = platforms::linux::ClockMonotonicRaw;
 using Random = platforms::stl::Random;
 #ifdef __linux__
