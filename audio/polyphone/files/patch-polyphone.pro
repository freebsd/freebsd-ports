--- polyphone.pro.orig	2025-01-17 04:49:42 UTC
+++ polyphone.pro
@@ -85,13 +85,13 @@ unix:!macx {
         lib/_option_rtaudio/rtaudio/include/iasiothiscallresolver.cpp
 }
 unix:!macx {
-    DEFINES += __LINUX_ALSASEQ__ __UNIX_JACK__ __LINUX_ALSA__ #__LINUX_PULSE__
+    DEFINES += __UNIX_JACK__ #__LINUX_PULSE__
     CONFIG += link_pkgconfig
-    PKGCONFIG += alsa jack zlib ogg vorbis vorbisfile vorbisenc sndfile
+    PKGCONFIG += jack zlib ogg vorbis vorbisfile vorbisenc sndfile
     contains(DEFINES, USE_WOLFSSL) {
-        PKGCONFIG += wolfssl
+        #PKGCONFIG += wolfssl
     } else {
-        PKGCONFIG += openssl
+        #PKGCONFIG += openssl
     }
     isEmpty(PREFIX) {
         PREFIX = /usr/local
