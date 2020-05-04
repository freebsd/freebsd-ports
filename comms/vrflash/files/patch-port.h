--- port.h.orig	2002-10-30 04:48:37 UTC
+++ port.h
@@ -1,8 +1,8 @@
 #define PORTLOG 1
 #define NOPORTLOG 0
 
-const char *prompt1;
-const char *prompt2;
+extern const char *prompt1;
+extern const char *prompt2;
 int port_open (char *filestr);
 void port_init (int fd);
 void port_send (int fd, char *str, int len, int log);
