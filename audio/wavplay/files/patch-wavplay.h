--- wavplay.h.orig	Thu Aug  5 17:24:45 2004
+++ wavplay.h	Thu Aug  5 17:24:49 2004
@@ -500,7 +500,7 @@
 extern int UnlockDSP(int ipc,int playrecx,ErrFunc erf);
 
 extern WAVFILE *WavOpenForRead(const char *Pathname,ErrFunc erf);
-extern WAVFILE *WavOpenForWrite(const char *Pathname,OprMode m,UInt32 sample_rate,UInt16 bits,UInt32 samples,ErrFunc erf);
+extern WAVFILE *WavOpenForWrite(const char *Pathname,Chan chmode,UInt32 sample_rate,UInt16 bits,UInt32 samples,ErrFunc erf);
 extern void WavReadOverrides(WAVFILE *wfile,WavPlayOpts *wavopts);
 extern int WavClose(WAVFILE *wfile,ErrFunc erf);
 
