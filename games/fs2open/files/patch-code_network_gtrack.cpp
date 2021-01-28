--- code/network/gtrack.cpp.orig	2021-01-27 17:07:03 UTC
+++ code/network/gtrack.cpp
@@ -27,6 +27,9 @@
 #include "network/ptrack.h"
 #include "network/multi_fstracker.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 // check structs for size compatibility
 SDL_COMPILE_TIME_ASSERT(game_packet_header, sizeof(game_packet_header) == 529);
