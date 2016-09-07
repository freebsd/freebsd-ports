--- src/VBox/Devices/Audio/DrvHostOSSAudio.cpp.orig	2016-08-16 19:57:22 UTC
+++ src/VBox/Devices/Audio/DrvHostOSSAudio.cpp
@@ -254,14 +254,14 @@ static int ossStreamClose(int *phFile)
 }
 
 
-static int ossStreamOpen(const char *pszDev, int fOpen, POSSAUDIOSTREAMCFG pReq, POSSAUDIOSTREAMCFG pObt, int *phFile)
+static int ossStreamOpen(const char *pszDev, bool fIn, POSSAUDIOSTREAMCFG pReq, POSSAUDIOSTREAMCFG pObt, int *phFile)
 {
     int rc;
 
     int hFile = -1;
     do
     {
-        hFile = open(pszDev, fOpen);
+        hFile = open(pszDev, (fIn ? O_RDONLY : O_WRONLY) | O_NONBLOCK);
         if (hFile == -1)
         {
             LogRel(("OSS: Failed to open %s: %s (%d)\n", pszDev, strerror(errno), errno));
@@ -312,7 +312,7 @@ static int ossStreamOpen(const char *psz
         }
 
         audio_buf_info abinfo;
-        if (ioctl(hFile, (fOpen & O_RDONLY) ? SNDCTL_DSP_GETISPACE : SNDCTL_DSP_GETOSPACE, &abinfo))
+        if (ioctl(hFile, fIn ? SNDCTL_DSP_GETISPACE : SNDCTL_DSP_GETOSPACE, &abinfo))
         {
             LogRel(("OSS: Failed to retrieve buffer length: %s (%d)\n", strerror(errno), errno));
             rc = RTErrConvertFromErrno(errno);
@@ -670,7 +670,7 @@ static int ossCreateStreamIn(PPDMAUDIOST
         reqStream.cFragments     = s_OSSConf.nfrags;
         reqStream.cbFragmentSize = s_OSSConf.fragsize;
 
-        rc = ossStreamOpen(s_OSSConf.devpath_in, O_RDONLY | O_NONBLOCK, &reqStream, &obtStream, &hFile);
+        rc = ossStreamOpen(s_OSSConf.devpath_in, true /* fIn */, &reqStream, &obtStream, &hFile);
         if (RT_SUCCESS(rc))
         {
             pCfgAcq->enmFormat     = obtStream.enmFormat;
@@ -742,7 +742,7 @@ static int ossCreateStreamOut(PPDMAUDIOS
         reqStream.cFragments     = s_OSSConf.nfrags;
         reqStream.cbFragmentSize = s_OSSConf.fragsize;
 
-        rc = ossStreamOpen(s_OSSConf.devpath_out, O_WRONLY | O_NONBLOCK, &reqStream, &obtStream, &hFile);
+        rc = ossStreamOpen(s_OSSConf.devpath_out, false /* fIn */, &reqStream, &obtStream, &hFile);
         if (RT_SUCCESS(rc))
         {
             pCfgAcq->enmFormat     = obtStream.enmFormat;
