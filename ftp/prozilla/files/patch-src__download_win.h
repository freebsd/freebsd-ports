--- ./src/download_win.h.orig	Wed Feb  8 14:18:59 2006
+++ ./src/download_win.h	Sun Dec 17 12:56:15 2006
@@ -52,7 +52,7 @@
   void handle_joining_thread();
   void handle_dl_fatal_error();
   void cleanup(boolean erase_dlparts);
-  void DL_Window::print_status(download_t * download, int quiet_mode);
+  void print_status(download_t * download, int quiet_mode);
 
   connection_t *connection;
   download_t *download;
