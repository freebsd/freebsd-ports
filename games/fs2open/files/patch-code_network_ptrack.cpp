--- code/network/ptrack.cpp.orig	2020-01-28 15:15:11 UTC
+++ code/network/ptrack.cpp
@@ -25,6 +25,9 @@
 #include "network/psnet2.h"
 #include "network/multi_fstracker.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 // check structs for size compatibility
 SDL_COMPILE_TIME_ASSERT(udp_packet_header, sizeof(udp_packet_header) == 497);
