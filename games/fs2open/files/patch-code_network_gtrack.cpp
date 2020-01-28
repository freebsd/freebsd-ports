--- code/network/gtrack.cpp.orig	2020-01-28 15:07:26 UTC
+++ code/network/gtrack.cpp
@@ -25,6 +25,9 @@
 #include "network/ptrack.h"
 #include "network/multi_fstracker.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 // check structs for size compatibility
 SDL_COMPILE_TIME_ASSERT(game_packet_header, sizeof(game_packet_header) == 529);
