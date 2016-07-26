--- src/hairtunes.h.orig	2011-08-20 22:06:21 UTC
+++ src/hairtunes.h
@@ -4,6 +4,8 @@
 int hairtunes_init(char *pAeskey, char *pAesiv, char *pFmtpstr, int pCtrlPort, int pTimingPort,
          int pDataPort, char *pRtpHost, char*pPipeName, char *pLibaoDriver, char *pLibaoDeviceName, char *pLibaoDeviceId);
 void hairtunes_setvolume(float vol);
+void hairtunes_set_metadata(const char *buffer, unsigned int size);
+void hairtunes_set_metadata_coverart(const char *buffer, unsigned int size);
 void hairtunes_flush(void);
 void hairtunes_cleanup(void);
 
