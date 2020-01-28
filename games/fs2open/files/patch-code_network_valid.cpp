--- code/network/valid.cpp.orig	2020-01-28 15:19:22 UTC
+++ code/network/valid.cpp
@@ -27,6 +27,9 @@
 #include "network/multi_fstracker.h"
 #include "io/timer.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 // check structs for size compatibility
 SDL_COMPILE_TIME_ASSERT(vmt_validate_mission_req_struct, sizeof(vmt_validate_mission_req_struct) == 104);
