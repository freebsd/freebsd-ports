--- src/hostapi/oss/pa_unix_oss.c.orig	2018-07-17 07:24:21 UTC
+++ src/hostapi/oss/pa_unix_oss.c
@@ -62,6 +62,9 @@
 #include <sys/poll.h>
 #include <limits.h>
 #include <semaphore.h>
+#ifdef __FreeBSD__
+#include <sys/sysctl.h>
+#endif
 
 #ifdef HAVE_SYS_SOUNDCARD_H
 # include <sys/soundcard.h>
@@ -525,7 +528,14 @@ static PaError BuildDeviceList( PaOSSHostApiRepresenta
     int i;
     int numDevices = 0, maxDeviceInfos = 1;
     PaDeviceInfo **deviceInfos = NULL;
+    int defaultDevice = 0;
 
+#ifdef __FreeBSD__
+    size_t len = sizeof(defaultDevice);
+    if (sysctlbyname("hw.snd.default_unit", &defaultDevice, &len, NULL, 0) == -1 || len != 4)
+       defaultDevice = 0;
+#endif
+
     /* These two will be set to the first working input and output device, respectively */
     commonApi->info.defaultInputDevice = paNoDevice;
     commonApi->info.defaultOutputDevice = paNoDevice;
@@ -541,7 +551,7 @@ static PaError BuildDeviceList( PaOSSHostApiRepresenta
        PaDeviceInfo *deviceInfo;
        int testResult;
 
-       if( i == 0 )
+       if( i == defaultDevice )
           snprintf(deviceName, sizeof (deviceName), "%s", DEVICE_NAME_BASE);
        else
           snprintf(deviceName, sizeof (deviceName), "%s%d", DEVICE_NAME_BASE, i);
@@ -2041,5 +2051,29 @@ static signed long GetStreamWriteAvailable( PaStream* 
 error:
     return result;
 #endif
+}
+
+const char *PaOSS_GetStreamInputDevice( PaStream* s )
+{
+    PaOssStream *stream = (PaOssStream*)s;
+
+    if( stream->capture )
+    {
+      return stream->capture->devName;
+    }
+
+   return NULL;
+}
+
+const char *PaOSS_GetStreamOutputDevice( PaStream* s )
+{
+    PaOssStream *stream = (PaOssStream*)s;
+
+    if( stream->playback )
+    {
+      return stream->playback->devName;
+    }
+
+   return NULL;
 }
 
