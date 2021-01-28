--- code/network/valid.cpp.orig	2021-01-27 17:07:03 UTC
+++ code/network/valid.cpp
@@ -29,6 +29,9 @@
 #include "network/multi_fstracker.h"
 #include "io/timer.h"
 
+#ifdef __FreeBSD__
+#include <sys/socket.h>
+#endif
 
 // check structs for size compatibility
 SDL_COMPILE_TIME_ASSERT(vmt_validate_mission_req_struct, sizeof(vmt_validate_mission_req_struct) == 104);
