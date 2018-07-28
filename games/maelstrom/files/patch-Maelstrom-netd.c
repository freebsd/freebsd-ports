Maelstrom-netd.c:48:10: warning: implicit declaration of function 'free' is invalid in C99 [-Wimplicit-function-declaration]
                (void) free(players[which].packet);
                       ^
Maelstrom-netd.c:62:3: warning: implicitly declaring library function 'exit' with type 'void (int) __attribute__((noreturn))' [-Wimplicit-function-declaration]
                exit(3);
                ^
Maelstrom-netd.c:62:3: note: include the header <stdlib.h> or explicitly provide a declaration for 'exit'
Maelstrom-netd.c:157:24: warning: implicit declaration of function 'inet_ntoa' is invalid in C99 [-Wimplicit-function-declaration]
                        strcpy(ptr, (char *)inet_ntoa(player->raddr.sin_addr));
                                            ^

--- Maelstrom-netd.c.orig	2018-07-28 05:49:43 UTC
+++ Maelstrom-netd.c
@@ -9,6 +9,8 @@
 #include <sys/time.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
+#include <arpa/inet.h>
+#include <stdlib.h>
 #include <netdb.h>
 #include <unistd.h>
 
