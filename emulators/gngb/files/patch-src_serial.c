--- src/serial.c.orig	2003-07-27 16:20:30 UTC
+++ src/serial.c
@@ -51,11 +51,16 @@
 #define SOCKET int
 #endif
 
+Sint8 gblisten;
+
 SDL_Thread *thread;
 int thread_fun(void *data);
 
 SOCKET dest_socket=-1;
 SOCKET listen_socket=-1;
+
+Sint16 serial_cycle_todo;
+gbserial_t gbserial;
 
 void gngb_closesocket(SOCKET s){
 #ifdef WIN32
