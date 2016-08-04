--- src/hostapi/oss/pa_unix_oss.c.orig	2013-06-08 19:30:41 UTC
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
@@ -525,6 +528,13 @@ static PaError BuildDeviceList( PaOSSHos
     int i;
     int numDevices = 0, maxDeviceInfos = 1;
     PaDeviceInfo **deviceInfos = NULL;
+    int defaultDevice = 0;
+
+#ifdef __FreeBSD__
+    size_t len = sizeof(defaultDevice);
+    if (sysctlbyname("hw.snd.default_unit", &defaultDevice, &len, NULL, 0) == -1 || len != 4)
+       defaultDevice = 0;
+#endif
 
     /* These two will be set to the first working input and output device, respectively */
     commonApi->info.defaultInputDevice = paNoDevice;
@@ -541,7 +551,7 @@ static PaError BuildDeviceList( PaOSSHos
        PaDeviceInfo *deviceInfo;
        int testResult;
 
-       if( i == 0 )
+       if( i == defaultDevice )
           snprintf(deviceName, sizeof (deviceName), "%s", DEVICE_NAME_BASE);
        else
           snprintf(deviceName, sizeof (deviceName), "%s%d", DEVICE_NAME_BASE, i);
