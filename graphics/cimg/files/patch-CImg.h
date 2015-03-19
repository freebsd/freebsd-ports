--- CImg.h.orig	2015-03-16 09:57:26 UTC
+++ CImg.h
@@ -2645,6 +2645,9 @@ namespace cimg_library_suffixed {
 #endif
       X11_info():nb_wins(0),events_thread(0),display(0),
                  nb_bits(0),is_blue_first(false),is_shm_enabled(false),byte_order(false) {
+#ifdef __FreeBSD__
+        XInitThreads();
+#endif
         wins = new CImgDisplay*[1024];
         pthread_mutex_init(&wait_event_mutex,0);
         pthread_cond_init(&wait_event,0);
