--- libsndio/sio.c.orig	2016-01-08 20:51:12 UTC
+++ libsndio/sio.c
@@ -64,6 +64,8 @@ sio_open(const char *str, unsigned int m
 			return hdl;
 #if defined(USE_SUN)
 		return _sio_sun_open("rsnd/0", mode, nbio);
+#elif defined(USE_OSS)
+		return _sio_oss_open("rsnd/0", mode, nbio);
 #elif defined(USE_ALSA)
 		return _sio_alsa_open("rsnd/0", mode, nbio);
 #else
@@ -75,6 +77,8 @@ sio_open(const char *str, unsigned int m
 	if (_sndio_parsetype(str, "rsnd"))
 #if defined(USE_SUN)
 		return _sio_sun_open(str, mode, nbio);
+#elif defined(USE_OSS)
+		return _sio_oss_open(str, mode, nbio);
 #elif defined(USE_ALSA)
 		return _sio_alsa_open(str, mode, nbio);
 #else
