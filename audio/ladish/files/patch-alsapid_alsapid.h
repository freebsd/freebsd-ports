--- alsapid/alsapid.h.orig	2023-12-18 22:37:53 UTC
+++ alsapid/alsapid.h
@@ -29,6 +29,8 @@
 
 #include "../common.h"
 
+#include <unistd.h> // for pid_t
+
 void alsapid_compose_src_link(int alsa_client_id, char * buffer);
 void alsapid_compose_dst_link(char * buffer);
 bool alsapid_get_pid(int alsa_client_id, pid_t * pid_ptr);
