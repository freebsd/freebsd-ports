--- src/libirc/Socket.h.orig	Mon Jul  1 01:17:10 2002
+++ src/libirc/Socket.h	Mon Jul  1 01:17:30 2002
@@ -22,6 +22,9 @@
 #include <netdb.h>
 #include <string>
 #include <exception>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
 #include <sigc++/signal_system.h>
 
 class Socket : public SigC::Object
END-of-lostirc/fileEND-of-lostirc/files/patch-libirc_Socket.h
exit

