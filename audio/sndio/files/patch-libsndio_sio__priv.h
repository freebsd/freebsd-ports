--- libsndio/sio_priv.h.orig	2015-01-17 23:09:04 UTC
+++ libsndio/sio_priv.h
@@ -69,6 +69,9 @@ struct sio_hdl *_sio_aucat_open(const ch
 #ifdef USE_SUN
 struct sio_hdl *_sio_sun_open(const char *, unsigned, int);
 #endif
+#ifdef USE_OSS
+struct sio_hdl *_sio_oss_open(const char *, unsigned, int);
+#endif
 #ifdef USE_ALSA
 struct sio_hdl *_sio_alsa_open(const char *, unsigned, int);
 #endif
