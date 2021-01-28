--- code/network/ptrack.cpp.orig	2021-01-27 17:07:03 UTC
+++ code/network/ptrack.cpp
@@ -27,6 +27,9 @@
 #include "network/psnet2.h"
 #include "network/multi_fstracker.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 // check structs for size compatibility
 SDL_COMPILE_TIME_ASSERT(udp_packet_header, sizeof(udp_packet_header) == 497);
