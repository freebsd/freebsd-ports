--- polyphone.pro.orig	2024-09-19 02:24:17 UTC
+++ polyphone.pro
@@ -82,13 +82,13 @@ unix:!macx {
         lib/_option_rtaudio/rtaudio/include/iasiothiscallresolver.cpp
 }
 unix:!macx {
-    DEFINES += __LINUX_ALSASEQ__ __UNIX_JACK__ __LINUX_ALSA__ #__LINUX_PULSE__
+    DEFINES += __UNIX_JACK__ #__LINUX_PULSE__
     CONFIG += link_pkgconfig
-    PKGCONFIG += alsa jack zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
+    PKGCONFIG += jack zlib ogg flac vorbis vorbisfile vorbisenc glib-2.0
     contains(DEFINES, USE_WOLFSSL) {
-        PKGCONFIG += wolfssl
+        #PKGCONFIG += wolfssl
     } else {
-        PKGCONFIG += openssl
+        #PKGCONFIG += openssl
     }
     isEmpty(PREFIX) {
         PREFIX = /usr/local
