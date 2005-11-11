--- src/vpbapi.h	Sat Feb 12 10:00:47 2005
+++ src/vpbapi.h	Sat Feb 12 10:01:56 2005
@@ -150,7 +150,7 @@
 
 \*-------------------------------------------------------------------------*/
 
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 int WINAPI vpb_set_station_sync(int handle, int state);
 int WINAPI vpb_ring_station_async(int handle, int state, int one_ring);
 int WINAPI vpb_user_ring_station_sync(int handle, int state);
