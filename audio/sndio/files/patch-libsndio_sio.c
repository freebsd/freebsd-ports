--- libsndio/sio.c.orig	2016-11-06 11:21:59 UTC
+++ libsndio/sio.c
@@ -65,7 +65,7 @@ sio_open(const char *str, unsigned int m
 #if defined(USE_SUN)
 		return _sio_sun_open("rsnd/0", mode, nbio);
 #elif defined(USE_OSS)
-		return _sio_oss_open("rsnd/0", mode, nbio);
+		return _sio_oss_open(SIO_DEVANY, mode, nbio);
 #elif defined(USE_ALSA)
 		return _sio_alsa_open("rsnd/0", mode, nbio);
 #else
