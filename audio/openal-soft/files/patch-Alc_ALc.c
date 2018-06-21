Prefer sndio over OSS when it's enabled.

--- Alc/ALc.c.orig	2018-06-21 02:27:21 UTC
+++ Alc/ALc.c
@@ -69,14 +69,14 @@ static struct BackendInfo BackendList[] = {
 #ifdef HAVE_COREAUDIO
     { "core", ALCcoreAudioBackendFactory_getFactory },
 #endif
-#ifdef HAVE_OSS
-    { "oss", ALCossBackendFactory_getFactory },
-#endif
 #ifdef HAVE_SOLARIS
     { "solaris", ALCsolarisBackendFactory_getFactory },
 #endif
 #ifdef HAVE_SNDIO
     { "sndio", ALCsndioBackendFactory_getFactory },
+#endif
+#ifdef HAVE_OSS
+    { "oss", ALCossBackendFactory_getFactory },
 #endif
 #ifdef HAVE_QSA
     { "qsa", ALCqsaBackendFactory_getFactory },
