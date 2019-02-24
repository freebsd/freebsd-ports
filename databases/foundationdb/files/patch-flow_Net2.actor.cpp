--- flow/Net2.actor.cpp.orig	2019-01-09 22:28:32 UTC
+++ flow/Net2.actor.cpp
@@ -56,7 +56,7 @@ uint64_t compatibleProtocolVersionMask = 0xfffffffffff
 uint64_t minValidProtocolVersion       = 0x0FDB00A200060001LL;
 
 
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <execinfo.h>
 
 volatile double net2liveness = 0;
