--- src/hairtunes.h.orig	2011-08-21 00:06:21.000000000 +0200
+++ src/hairtunes.h	2012-10-09 12:09:33.000000000 +0200
@@ -4,6 +4,8 @@
 int hairtunes_init(char *pAeskey, char *pAesiv, char *pFmtpstr, int pCtrlPort, int pTimingPort,
          int pDataPort, char *pRtpHost, char*pPipeName, char *pLibaoDriver, char *pLibaoDeviceName, char *pLibaoDeviceId);
 void hairtunes_setvolume(float vol);
+void hairtunes_set_metadata(const char *buffer, unsigned int size);
+void hairtunes_set_metadata_coverart(const char *buffer, unsigned int size);
 void hairtunes_flush(void);
 void hairtunes_cleanup(void);
 
