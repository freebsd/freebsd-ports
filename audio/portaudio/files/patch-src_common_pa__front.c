--- src/common/pa_front.c.orig	2018-07-17 06:44:39 UTC
+++ src/common/pa_front.c
@@ -1216,8 +1216,10 @@ PaError Pa_OpenStream( PaStream** stream,
                                   hostApiInputParametersPtr, hostApiOutputParametersPtr,
                                   sampleRate, framesPerBuffer, streamFlags, streamCallback, userData );
 
-    if( result == paNoError )
+    if( result == paNoError ) {
         AddOpenStream( *stream );
+        PA_STREAM_REP(*stream)->hostApiType = hostApi->info.type;
+    }
 
 
     PA_LOGAPI(("Pa_OpenStream returned:\n" ));
@@ -1729,6 +1731,32 @@ signed long Pa_GetStreamWriteAvailable( PaStream* stre
     return result;
 }
 
+PaHostApiTypeId Pa_GetStreamHostApiType( PaStream* stream )
+{
+    PaError error = PaUtil_ValidateStreamPointer( stream );
+    PaHostApiTypeId result;
+
+#ifdef PA_LOG_API_CALLS
+    PaUtil_DebugPrint("Pa_GetStreamHostApiType called:\n" );
+    PaUtil_DebugPrint("\tPaStream* stream: 0x%p\n", stream );
+#endif
+
+    if( error == paNoError )
+    {
+        result = PA_STREAM_REP(stream)->hostApiType;
+    }
+    else
+    {
+        result = (PaHostApiTypeId) error;
+    }
+
+#ifdef PA_LOG_API_CALLS
+    PaUtil_DebugPrint("Pa_GetStreamHostApiType returned:\n" );
+    PaUtil_DebugPrint("\tPaError: %d ( %s )\n\n", result, Pa_GetErrorText( result ) );
+#endif
+
+    return result;
+}
 
 PaError Pa_GetSampleSize( PaSampleFormat format )
 {
