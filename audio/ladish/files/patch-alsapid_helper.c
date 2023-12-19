--- alsapid/helper.c.orig	2023-12-18 22:35:47 UTC
+++ alsapid/helper.c
@@ -33,6 +33,8 @@
 #include <unistd.h>
 #include <sys/types.h>
 
+#include <libgen.h>
+
 void alsapid_compose_src_link(int alsa_client_id, char * buffer)
 {
   sprintf(buffer, "/tmp/alsapid-%lld-%d", (long long)getuid(), alsa_client_id);
