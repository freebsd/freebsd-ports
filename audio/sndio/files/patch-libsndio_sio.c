--- libsndio/sio.c.orig	2016-01-08 20:51:12 UTC
+++ libsndio/sio.c
@@ -64,17 +64,25 @@ sio_open(const char *str, unsigned int m
 			return hdl;
 #if defined(USE_SUN)
 		return _sio_sun_open("rsnd/0", mode, nbio);
+#elif defined(USE_OSS)
+		return _sio_oss_open("fallback", mode, nbio);
 #elif defined(USE_ALSA)
 		return _sio_alsa_open("rsnd/0", mode, nbio);
 #else
 		return NULL;
 #endif
 	}
+#if defined(USE_OSS)
+	if (strcmp(str, "fallback") == 0)
+		return _sio_oss_open(str, mode, nbio);
+#endif
 	if (_sndio_parsetype(str, "snd"))
 		return _sio_aucat_open(str, mode, nbio);
 	if (_sndio_parsetype(str, "rsnd"))
 #if defined(USE_SUN)
 		return _sio_sun_open(str, mode, nbio);
+#elif defined(USE_OSS)
+		return _sio_oss_open(str, mode, nbio);
 #elif defined(USE_ALSA)
 		return _sio_alsa_open(str, mode, nbio);
 #else
