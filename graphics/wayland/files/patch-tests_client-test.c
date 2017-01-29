--- tests/client-test.c.orig	2015-07-06 19:38:51 UTC
+++ tests/client-test.c
@@ -34,6 +34,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 
+#include "wayland-os.h"
 #include "wayland-private.h"
 #include "wayland-server.h"
 #include "test-runner.h"
@@ -59,7 +60,7 @@ TEST(client_destroy_listener)
 	struct client_destroy_listener a, b;
 	int s[2];
 
-	assert(socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, s) == 0);
+	assert(wl_os_socketpair_cloexec(AF_UNIX, SOCK_STREAM, 0, s) == 0);
 	display = wl_display_create();
 	assert(display);
 	client = wl_client_create(display, s[0]);
