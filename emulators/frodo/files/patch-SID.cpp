--- SID.cpp.orig	2002-01-02 21:18:59.000000000 +0000
+++ SID.cpp	2004-11-27 15:51:44.000000000 +0000
@@ -428,7 +428,7 @@
 	int play_buf;					// Number of buffer currently playing
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 	int devfd, sndbufsize, buffer_rate;
 	int16 *sound_buffer;
 #endif
@@ -1351,7 +1351,7 @@
 #elif defined(AMIGA)
 #include "SID_Amiga.i"
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #include "SID_linux.i"
 
 #elif defined(SUN)
