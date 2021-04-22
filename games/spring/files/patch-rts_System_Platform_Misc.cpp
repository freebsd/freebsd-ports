--- rts/System/Platform/Misc.cpp.orig	2021-01-01 16:12:22 UTC
+++ rts/System/Platform/Misc.cpp
@@ -29,7 +29,9 @@
 	#include <mach-o/dyld.h>
 
 #elif defined( __FreeBSD__)
+	#include <sys/types.h>
 	#include <sys/sysctl.h>
+	#include <ifaddrs.h>
 
 #else
 
@@ -714,7 +716,7 @@ namespace Platform
 		return (GetMacType(macAddr, 0), macAddr);
 	}
 
-	#elif defined(__APPLE__)
+	#elif defined(__APPLE__) || defined (__FreeBSD__)
 
 	std::array<uint8_t, 6> GetRawMacAddr() {
 		// TODO: http://lists.freebsd.org/pipermail/freebsd-hackers/2004-June/007415.html
