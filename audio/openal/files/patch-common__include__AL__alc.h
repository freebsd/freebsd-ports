--- ./common/include/AL/alc.h.orig	Sat Feb 11 12:36:55 2006
+++ ./common/include/AL/alc.h	Sat Jul 14 19:33:48 2007
@@ -187,7 +187,7 @@
 
 ALC_API void            ALC_APIENTRY alcDestroyContext( ALCcontext *context );
 
-ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( ALCvoid );
+ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( void );
 
 ALC_API ALCdevice*      ALC_APIENTRY alcGetContextsDevice( ALCcontext *context );
 
@@ -248,7 +248,7 @@
 typedef void           (ALC_APIENTRY *LPALCPROCESSCONTEXT)( ALCcontext *context );
 typedef void           (ALC_APIENTRY *LPALCSUSPENDCONTEXT)( ALCcontext *context );
 typedef void           (ALC_APIENTRY *LPALCDESTROYCONTEXT)( ALCcontext *context );
-typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( ALCvoid );
+typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( void );
 typedef ALCdevice *    (ALC_APIENTRY *LPALCGETCONTEXTSDEVICE)( ALCcontext *context );
 typedef ALCdevice *    (ALC_APIENTRY *LPALCOPENDEVICE)( const ALCchar *devicename );
 typedef ALCboolean     (ALC_APIENTRY *LPALCCLOSEDEVICE)( ALCdevice *device );
