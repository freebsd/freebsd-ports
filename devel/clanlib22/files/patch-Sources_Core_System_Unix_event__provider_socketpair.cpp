--- Sources/Core/System/Unix/event_provider_socketpair.cpp.orig	2011-01-13 11:17:34 UTC
+++ Sources/Core/System/Unix/event_provider_socketpair.cpp
@@ -45,7 +45,7 @@ CL_EventProvider_Socketpair::CL_EventPro
 	// Not sure if its better to use 0 or PF_UNIX for Linux then. The
 	// documentation for socketpair is not that clear about the
 	// difference. -- mbn 15 april 2005
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 	int result = socketpair(AF_UNIX, SOCK_DGRAM, 0, wait_sockets);
 #else
 	int result = socketpair(AF_UNIX, SOCK_DGRAM, PF_UNIX, wait_sockets);
