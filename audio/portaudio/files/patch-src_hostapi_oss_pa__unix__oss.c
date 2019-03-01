--- src/hostapi/oss/pa_unix_oss.c.orig	2019-03-01 03:09:23 UTC
+++ src/hostapi/oss/pa_unix_oss.c
@@ -535,13 +535,13 @@ static PaError BuildDeviceList( PaOSSHostApiRepresenta
      * add it to a linked list.
      * A: Set an arbitrary of 100 devices, should probably be a smarter way. */
 
-    for( i = 0; i < 100; i++ )
+    for( i = -1; i < 100; i++ )
     {
        char deviceName[32];
        PaDeviceInfo *deviceInfo;
        int testResult;
 
-       if( i == 0 )
+       if( i == -1 )
           snprintf(deviceName, sizeof (deviceName), "%s", DEVICE_NAME_BASE);
        else
           snprintf(deviceName, sizeof (deviceName), "%s%d", DEVICE_NAME_BASE, i);
@@ -2041,5 +2041,29 @@ static signed long GetStreamWriteAvailable( PaStream* 
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
 
