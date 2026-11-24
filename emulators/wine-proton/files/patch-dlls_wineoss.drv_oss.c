--- dlls/wineoss.drv/oss.c.orig	2025-11-06 09:54:15 UTC
+++ dlls/wineoss.drv/oss.c
@@ -155,17 +155,6 @@ static NTSTATUS oss_test_connect(void *args)
 
     close(mixer_fd);
 
-    if(sysinfo.version[0] < '4' || sysinfo.version[0] > '9'){
-        TRACE("Priority_Low: sysinfo.version[0]: %x\n", sysinfo.version[0]);
-        params->priority = Priority_Low;
-        return STATUS_SUCCESS;
-    }
-    if(sysinfo.versionnum & 0x80000000){
-        TRACE("Priority_Low: sysinfo.versionnum: %x\n", sysinfo.versionnum);
-        params->priority = Priority_Low;
-        return STATUS_SUCCESS;
-    }
-
     TRACE("Priority_Preferred: Seems like valid OSS!\n");
 
     params->priority = Priority_Preferred;
@@ -1131,7 +1120,7 @@ static NTSTATUS oss_get_mix_format(void *args)
     struct get_mix_format_params *params = args;
     WAVEFORMATEXTENSIBLE *fmt = params->fmt;
     oss_audioinfo ai;
-    int formats, fd;
+    int formats, getfmts, fd;
 
     if(params->flow != eRender && params->flow != eCapture){
         params->result = E_UNEXPECTED;
@@ -1152,22 +1141,31 @@ static NTSTATUS oss_get_mix_format(void *args)
         params->result = E_FAIL;
         return STATUS_SUCCESS;
     }
+    /* ENGINEINFO only lists the formats of the engine itself (on FreeBSD,
+     * the virtual channel format); GETFMTS also lists those the driver
+     * converts from. */
+    if(ioctl(fd, SNDCTL_DSP_GETFMTS, &getfmts) < 0)
+        getfmts = 0;
     close(fd);
 
     if(params->flow == eRender)
-        formats = ai.oformats;
+        formats = ai.oformats | getfmts;
     else
-        formats = ai.iformats;
+        formats = ai.iformats | getfmts;
 
-    fmt->Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
-    if(formats & AFMT_S16_LE){
-        fmt->Format.wBitsPerSample = 16;
-        fmt->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
+    /* Windows always reports 32-bit float as the shared mode mix format, and
+     * some applications (e.g. Wwise) write float samples whatever format
+     * they initialized the stream with. */
+    fmt->Format.wFormatTag = WAVE_FORMAT_EXTENSIBLE;
 #ifdef AFMT_FLOAT
-    }else if(formats & AFMT_FLOAT){
+    if(formats & AFMT_FLOAT){
         fmt->Format.wBitsPerSample = 32;
         fmt->SubFormat = KSDATAFORMAT_SUBTYPE_IEEE_FLOAT;
+    }else
 #endif
+    if(formats & AFMT_S16_LE){
+        fmt->Format.wBitsPerSample = 16;
+        fmt->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
     }else if(formats & AFMT_U8){
         fmt->Format.wBitsPerSample = 8;
         fmt->SubFormat = KSDATAFORMAT_SUBTYPE_PCM;
