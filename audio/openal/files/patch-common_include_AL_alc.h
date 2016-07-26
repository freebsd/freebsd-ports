--- common/include/AL/alc.h.orig	2006-02-11 09:36:55 UTC
+++ common/include/AL/alc.h
@@ -187,7 +187,7 @@ ALC_API void            ALC_APIENTRY alc
 
 ALC_API void            ALC_APIENTRY alcDestroyContext( ALCcontext *context );
 
-ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( ALCvoid );
+ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( void );
 
 ALC_API ALCdevice*      ALC_APIENTRY alcGetContextsDevice( ALCcontext *context );
 
@@ -248,7 +248,7 @@ typedef ALCboolean     (ALC_APIENTRY *LP
 typedef void           (ALC_APIENTRY *LPALCPROCESSCONTEXT)( ALCcontext *context );
 typedef void           (ALC_APIENTRY *LPALCSUSPENDCONTEXT)( ALCcontext *context );
 typedef void           (ALC_APIENTRY *LPALCDESTROYCONTEXT)( ALCcontext *context );
-typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( ALCvoid );
+typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( void );
 typedef ALCdevice *    (ALC_APIENTRY *LPALCGETCONTEXTSDEVICE)( ALCcontext *context );
 typedef ALCdevice *    (ALC_APIENTRY *LPALCOPENDEVICE)( const ALCchar *devicename );
 typedef ALCboolean     (ALC_APIENTRY *LPALCCLOSEDEVICE)( ALCdevice *device );
